#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "misc.h"

void InitPWN();
void InitUSART();

void USART3_IRQHandler(void)
{
	// sprawdzenie flagi zwiazanej z odebraniem danych przez USART
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		if(USART3->DR == 'w')
		{
			TIM4->CCR1 = 0;
			TIM4->CCR3 = 0;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == 's')
		{
			TIM4->CCR1 = TIM4->ARR;
			TIM4->CCR3 = TIM4->ARR;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == 'a')
		{
			TIM4->CCR1 = 0;
			TIM4->CCR3 = TIM4->ARR;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == 'd')
		{
			TIM4->CCR1 = TIM4->ARR;
			TIM4->CCR3 = 0;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == '1')
		{
			TIM4->CCR1 = 0;
			TIM4->CCR3 = 0;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == '5')
		{
			TIM4->CCR1 = TIM4->ARR;
			TIM4->CCR3 = TIM4->ARR;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == '0')
		{
			TIM4->CCR1 = 0;
			TIM4->CCR3 = 30000;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == '2')
		{
			TIM4->CCR1 = 30000;
			TIM4->CCR3 = 0;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == '4')
		{
			TIM4->CCR1 = 0;
			TIM4->CCR3 = TIM4->ARR;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == '6')
		{
			TIM4->CCR1 = TIM4->ARR;
			TIM4->CCR3 = 0;
			TIM4->CCR2 = TIM4->ARR;
			TIM4->CCR4 = TIM4->ARR;
		}

		if(USART3->DR == '9')
		{
			TIM4->CCR1 = TIM4->ARR;
			TIM4->CCR3 = TIM4->ARR;
			TIM4->CCR2 = 0;
			TIM4->CCR4 = 0;
		}
	}
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	InitPWN();
	InitUSART();

	while(1)
	{
	}

}

void InitPWN()
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	TIM_OCInitTypeDef TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_Cmd(TIM4, ENABLE);


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_Cmd(TIM4, ENABLE);


	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_Cmd(TIM4, ENABLE);


	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_Cmd(TIM4, ENABLE);


	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(GPIOD, &GPIO_InitStructure);


	TIM4->CCR1 = TIM4->ARR;
	TIM4->CCR2 = TIM4->ARR;
	TIM4->CCR3 = TIM4->ARR;
	TIM4->CCR4 = TIM4->ARR;

}

void InitUSART()
{


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOC, &GPIO_InitStructure);


	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	
	USART_Init(USART3, &USART_InitStructure);
	USART_Cmd(USART3, ENABLE);
	
	
	// PRZERWANIA, aby odrebac dane
	NVIC_InitTypeDef NVIC_InitStructure;
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_EnableIRQ(USART3_IRQn);
}


