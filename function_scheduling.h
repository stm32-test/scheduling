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
 * 任务调度
 */
struct fun_scheduling_struct{
    void (*function)(void);/*!< 函数名,不带参数的    */
    uint32_t interval;     /*!< 间隔时间    */
    uint8_t id;            /*!< id    */
};

/**
 * 添加函数到任务调度
 */
void add_fun_scheduling(void (*function)(void), uint32_t interval);
/**
 * 添加函数到任务调度
 */
void add_fun_scheduling_struct(struct fun_scheduling_struct *fun, uint8_t num);
/**
 * 任务调度循环
 */
void fun_scheduling_loop(void);

#endif /* FUNCTION_SCHEDULING_H_ */
