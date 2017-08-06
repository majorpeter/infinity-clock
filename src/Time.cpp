/*
 * Time.cpp
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#include "Time.h"

Time now;

extern "C"
void SysTick_Handler(void) {
	now.addMsec(1);
}

Time::Time() {
	sec = 0;
	msec = 0;
	usec = 0;
}

Time Time::now() {
	return ::now;
}

void Time::addMsec(uint16_t msec) {
	this->msec += msec;
	this->normalize();
}

void Time::normalize() {
	if (usec >= 1000) {
		msec += usec / 1000;
		usec %= 1000;
	}
	if (msec >= 1000) {
		sec += msec / 1000;
		msec %= 1000;
	}
}
