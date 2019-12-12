/*
 * function_scheduling.c
 *
 *  Created on: Nov 7, 2019
 *      Author: caijie
 */

#include "function_scheduling.h"

uint32_t scheduling_time[SCHEDULING_MAX_NUM];
uint8_t scheduling_num = 0;

struct fun_scheduling_struct fun_loop[SCHEDULING_MAX_NUM] = {0};

void add_fun_scheduling_struct(struct fun_scheduling_struct *fun, uint8_t num)
{
    for(uint8_t i = 0; i < num; i++)
    {
        if(scheduling_num > SCHEDULING_MAX_NUM) {
            return;
        }
        fun_loop[scheduling_num + i].function = fun[i].function;
        fun_loop[scheduling_num + i].interval = fun[i].interval;
    }
    scheduling_num = scheduling_num + num;
}
void add_fun_scheduling(void (*function)(void), uint32_t interval)
{
    if(scheduling_num > SCHEDULING_MAX_NUM) {
        return;
    }
    fun_loop[scheduling_num].function = function;
    fun_loop[scheduling_num].interval = interval;
    fun_loop[scheduling_num].id = scheduling_num + 1;
    scheduling_num = scheduling_num + 1;
}
void fun_scheduling_loop(void)
{
    for(uint8_t i = 0; i < scheduling_num; i++)
    {
        if((HAL_GetTick() - scheduling_time[i]) >= fun_loop[i].interval)
        {
            scheduling_time[i] = HAL_GetTick();
            if(fun_loop[i].function != NULL){
                fun_loop[i].function();
            }
        }
    }
}
