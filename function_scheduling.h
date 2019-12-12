/*
 * function_scheduling.h
 *
 *  Created on: Nov 7, 2019
 *      Author: caijie
 */

#ifndef FUNCTION_SCHEDULING_H_
#define FUNCTION_SCHEDULING_H_
#include <hwdef.h>

#define SCHEDULING_MAX_NUM 64
/**
 * �������
 */
struct fun_scheduling_struct{
    void (*function)(void);/*!< ������,����������    */
    uint32_t interval;     /*!< ���ʱ��    */
    uint8_t id;            /*!< id    */
};

/**
 * ��Ӻ������������
 */
void add_fun_scheduling(void (*function)(void), uint32_t interval);
/**
 * ��Ӻ������������
 */
void add_fun_scheduling_struct(struct fun_scheduling_struct *fun, uint8_t num);
/**
 * �������ѭ��
 */
void fun_scheduling_loop(void);

#endif /* FUNCTION_SCHEDULING_H_ */
