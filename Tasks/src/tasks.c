/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2026-10-06 15:15:05
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2026-10-06 20:06:51
 * @FilePath: \EC_homework01\Tasks\src\tasks.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "tasks.h"

extern IWDG_HandleTypeDef hiwdg;
extern TIM_HandleTypeDef htim2;

/* 第二题：1，喂狗；第三题：0，不喂狗 */
#define FEED_WATCHDOG 0

volatile uint32_t tick = 0;

void Tasks_Init(void)
{
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

    HAL_TIM_Base_Start_IT(&htim2);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        tick++;

#if FEED_WATCHDOG
        HAL_IWDG_Refresh(&hiwdg);
#endif
    }
}