/*
 * Hardware.h
 *
 *  Created on: 2017. aug. 5.
 *      Author: peti
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

namespace Hardware {

void RCC_Init();
void GPIO_Remap();
void SysTickInit();
void RTC_Init();

}

#endif /* HARDWARE_H_ */
