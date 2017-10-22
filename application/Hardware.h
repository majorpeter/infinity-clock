/*
 * Hardware.h
 *
 *  Created on: 2017. aug. 5.
 *      Author: peti
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

#include <stm32f10x.h>

class Qep;

namespace Hardware {

static GPIO_TypeDef * const LedStripDataOutPort = GPIOB;
static const uint16_t LedStripDataOutPin =  GPIO_Pin_3;

static const uint16_t LedOffset = 29;
static const bool LedsReversed = true;

static GPIO_TypeDef * const QepPortCOM = GPIOA;
static const uint16_t QepPinCOM = GPIO_Pin_0;
static GPIO_TypeDef * const QepPortA = GPIOA;
static const uint16_t QepPinA = GPIO_Pin_2;
static GPIO_TypeDef * const QepPortB = GPIOA;
static const uint16_t QepPinB = GPIO_Pin_3;

void RCC_Init();
void GPIO_Remap();
void SysTickInit();
void RTC_Init();
void IRQ_Init();

Qep* createRotaryEncoder();

}

#endif /* HARDWARE_H_ */
