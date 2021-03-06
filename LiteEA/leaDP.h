/*
 ============================================================================
 Name        : leaDP.h
 Author      : morris
 Version     :
 Copyright   : Your copyright notice
 Description : 动态规划类题目
 ============================================================================
 */

#ifndef LITEEA_LEADP_H_
#define LITEEA_LEADP_H_

#ifdef __cplusplus
extern "C" {
#endif
/**
 * 最长公共子序列/串(LCS)
 */
int LCS(int* x, int* y, int m, int n, int** result, int** path, int continous);
/**
 * 打印LCS
 */
void printLCS(int* x, int* y, int m, int n, int** result, int** path, int max);

/**
 * 最长递增子序列(LIS)
 */
int LIS(int* x, int n, int* result, int* path);
/**
 * 打印LIS
 */
void printLIS(int* x, int n, int* result, int* path, int max);

/**
 * 背包问题
 */
int Knapsack(int count, int capacity, int* weight, int* value, int* check);

/**
 * 整数划分
 */
int IntegerPart(int n);

#ifdef __cplusPlus
}
#endif
#endif /* LITEEA_LEADP_H_ */
