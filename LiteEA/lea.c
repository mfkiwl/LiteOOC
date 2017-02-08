/*
 ============================================================================
 Name        : lea.c
 Author      : morris
 Version     :
 Copyright   : Your copyright notice
 Description : 一些工程算法或面试题目
 ============================================================================
 */
#include "lea.h"

/**
 * 验证一个数组是否是一个二叉查找树的后序遍历结果
 * @param  squence 待验证的数组
 * @param  length  数组长度
 * @return         验证通过返回looc_true，否则返回looc_false
 */
looc_bool verifySquenceOfBST(int squence[], int length) {
	if (squence == NULL || length <= 0) {
		return looc_false;
	}
	/* 二叉查找树的根节点是后序遍历的最后一个元素 */
	int root = squence[length - 1];
	/* 左子树的节点小于根节点 */
	int i = 0;
	for (; i < length - 1; i++) {
		if (squence[i] > root) {
			break;
		}
	}
	/* 右子树的元素应该大于根节点 */
	int j = i;
	for (; j < length - 1; j++) {
		if (squence[j] < root) {
			return looc_false;
		}
	}
	/* 递归验证左子树是不是一个BST */
	looc_bool left = looc_true;
	if (i > 0) {
		left = verifySquenceOfBST(squence, i);
	}
	/* 递归验证右子树是不是一个BST */
	looc_bool right = looc_true;
	if (i < length - 1) {
		right = verifySquenceOfBST(squence + i, length - i - 1);
	}
	return (left & right);
}

static void _transNum(int origin, int num, int d, char result[]) {
	static int noEnd = 1;
	static int i = 0;
	int mod;

	if (num == origin) {
		i = 0;
		noEnd = 1;
	}

	mod = num % d;
	num = num / d;
	while (noEnd && num) {
		_transNum(origin, num, d, result);
	}
	noEnd = 0;
	if (mod >= 10) {
		mod = mod - 10 + 'A';
	} else {
		mod = mod + '0';
	}
	result[i++] = mod;
	result[i] = '\0';
}

/**
 * 数制转换(辗转相除)
 * @param num    待转换的数字
 * @param d      进制
 * @param result 存放转换后的字符串
 */
void transNum(int num, int d, char result[]) {
	_transNum(num, num, d, result);
}

/**
 * 判断CPU是否是小端模式
 * @return  如果是小端模式返回1，否则返回0
 */
int isLittleEndian(void) {
	union w {
		int a;
		char b;
	} c;
	c.a = 1;
	if (c.b == 1) {
		return 1;
	}
	return 0;
}

