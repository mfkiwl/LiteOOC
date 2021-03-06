/*
 ============================================================================
 Name        : loocSeqList.h
 Author      : morris
 Version     :
 Copyright   : Your copyright notice
 Description : 顺序表
 ============================================================================
 */

#ifndef LITEOOC_LOOCSEQLIST_H_
#define LITEOOC_LOOCSEQLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "looc.h"
#include "loocObject.h"

	/* 顺序表默认大小 */
#define LOOC_SEQLIST_DEFAULT_SIZE		(10)

	/**
	 * 顺序表的具体类
	 */
	CLASS(loocSeqList) {
		/* 继承自loocObject */
		EXTENDS(loocObject);
		/* 顺序表的有效长度 */
		int length;
		/* 顺序表最大的大小 */
		int _maxSize;
		/* 顺序表中每个元素的大小 */
		int _elementSize;
		/* 顺序表表头指针 */
		void* head;
		/* 初始化一个顺序表*/
		void (*init)(loocSeqList* cthis, int maxSize, int elementSize);
		/* 顺序表的插入操作:插入顺序表末尾 */
		looc_bool (*insert)(loocSeqList* cthis, void* data);
		/* 删除指定位置的元素,location从0开始计数 */
		looc_bool (*removeAt)(loocSeqList* cthis, int location);
		/* 获取指定位置的元素,location从0开始计数 */
		void* (*getAt)(loocSeqList* cthis, int location);
		/* 修改指定位置的元素,location从0开始计数 */
		looc_bool (*modifyAt)(loocSeqList* cthis, int location, void* newData);
	};

#ifdef __cplusPlus
}
#endif

#endif /* LITEOOC_LOOCSEQLIST_H_ */
