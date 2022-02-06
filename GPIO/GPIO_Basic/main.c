/**
	******************************************************************************
	* @file    Project/GPIO/GPIO_Basic/main.c
	* @author  Geunhyeok Lee
	* @version V0.0.1
	* @date    05-February-2022
	* @brief   Main program
	******************************************************************************
	*/

#include "main.h"

int main()
{
	GPIO_Configuration();
	
	GPIO_WriteBit(GPIOD, GPIO_Pin_12, Bit_SET);
	GPIO_WriteBit(GPIOD, GPIO_Pin_13, Bit_SET);
	GPIO_WriteBit(GPIOD, GPIO_Pin_14, Bit_SET);
	GPIO_WriteBit(GPIOD, GPIO_Pin_15, Bit_SET);

	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == SET)
		{
			GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
			GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
			GPIO_ToggleBits(GPIOD, GPIO_Pin_14);
			GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
		}
	}
	
  return 0;
}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Medium_Speed;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Medium_Speed;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}
/******************************** END OF FILE *********************************/