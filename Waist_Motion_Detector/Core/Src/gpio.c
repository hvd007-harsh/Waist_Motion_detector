/*
 * gpio.c
 *
 *  Created on: 02-Apr-2023
 *      Author: harsh
 */

#include "gpio.h"

void MX_GPIO_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;

    /*
     * GPIO ports Enable
     */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	//Configure GPIO pins output level

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_RESET);

	//Configure the GPIO pins : PAPin PAPin

	GPIO_InitStruct.Pin=GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}
