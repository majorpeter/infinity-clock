/*
 * Hardware.cpp
 *
 *  Created on: 2017. aug. 5.
 *      Author: peti
 */

#include "Hardware.h"

#include "qep/QepStm32F1Gpio.h"
#include "FunctionButton.h"

namespace Hardware {

void RCC_Init() {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP | RCC_APB1Periph_PWR, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
}

void GPIO_Remap() {
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
}

/**
 * Configure SysTick interrupt in every 1ms
 */
void SysTickInit() {
    SysTick_Config(SystemCoreClock / 1000);
}

void RTC_Init() {
    static const uint16_t BKP_VALIDITY_PATTERN = 0xA5A5;

    if (BKP_ReadBackupRegister(BKP_DR1) != BKP_VALIDITY_PATTERN) {
        /* Backup data register value is not correct or not yet programmed
           (when the first time the program is executed) */
        /* Allow access to BKP Domain */
        PWR_BackupAccessCmd(ENABLE);

        /* Reset Backup Domain */
        BKP_DeInit();

        /* Enable LSE */
        RCC_LSEConfig(RCC_LSE_ON);

        /* Wait till LSE is ready */
        while(!RCC_GetFlagStatus(RCC_FLAG_LSERDY));

        /* Select LSE as RTC Clock Source */
        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

        /* Enable RTC Clock */
        RCC_RTCCLKCmd(ENABLE);

        /* Wait for RTC registers synchronization */
        RTC_WaitForSynchro();

        /* Wait until last write operation on RTC registers has finished */
        RTC_WaitForLastTask();

        /* Set RTC prescaler: set RTC period to 1sec */
        RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */

        /* Wait until last write operation on RTC registers has finished */
        RTC_WaitForLastTask();

        /* Set initial value */
        RTC_SetCounter(0);

        /* Wait until last write operation on RTC registers has finished */
        RTC_WaitForLastTask();

        BKP_WriteBackupRegister(BKP_DR1, BKP_VALIDITY_PATTERN);

        /* Lock access to BKP Domain */
        PWR_BackupAccessCmd(DISABLE);
    }
    else {
        /* Wait for RTC registers synchronization */
        RTC_WaitForSynchro();
    }
}

void IRQ_Init() {
    // 4 bits for pre-emption priority: NVIC_IRQChannelPreemptionPriority = 0..15
    // 0 bits for subpriority:          NVIC_IRQChannelSubPriority        = 0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

    NVIC_InitTypeDef    NVIC_InitStructure;

    // DMA1 Channel7
    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel7_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // TIM2
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

Qep* createRotaryEncoder() {
    // the rotary encoder's COM pin must be pulled high
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = QepPinCOM;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(QepPortCOM, &GPIO_InitStruct);

    GPIO_SetBits(QepPortCOM, QepPinCOM);

    Qep* qep = new QepStm32F1Gpio(QepPortA, QepPinA, QepPortB, QepPinB, true);
    qep->init();

    return qep;
}

FunctionButton* createFunctionButton() {
    FunctionButton* button = new FunctionButton(FunctionButtonPort, FunctionButtonPin);
    button->init();
    return button;
}

}
