/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#include"FreeRTOSConfig.h"
#include"FreeRTOS.h"
#include"task.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif




typedef struct struct_t{

	uint32_t pin_no;
	uint32_t rate;

}data_t;

   	   data_t d1 =  { .pin_no=12,.rate = 1000};
   	   data_t d2 = { .pin_no=13,.rate = 2000};
   	   data_t d3 = { .pin_no=14,.rate = 3000};
   	   data_t d4 = { .pin_no=15,.rate = 4000};

void vLedTask(void * pvParam)
{
	data_t * data = (data_t *) pvParam;
	portTickType xLastWakeupTime;

	while(1)
	{
		xLastWakeupTime = xTaskGetTickCount();
		led_toggle(data->pin_no);
		vTaskDelayUntil(&xLastWakeupTime, data->rate/portTICK_RATE_MS);

	}
		vTaskDelete(NULL);
}



int main(void)
{

	led_init(12);
	led_init(13);
	led_init(14);
	led_init(15);
	xTaskCreate(vLedTask,"Task1",configMINIMAL_STACK_SIZE,(void*)&d1,4,NULL);
	xTaskCreate(vLedTask,"Task2",configMINIMAL_STACK_SIZE,(void*)&d2,3,NULL);
	xTaskCreate(vLedTask,"Task3",configMINIMAL_STACK_SIZE,(void*)&d3,2,NULL);
	xTaskCreate(vLedTask,"Task4",configMINIMAL_STACK_SIZE,(void*)&d4,5,NULL);

		vTaskStartScheduler();
		while(1);
}










