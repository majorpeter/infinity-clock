/*
 * Time.cpp
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#include "Time.h"
#ifdef STM32F10X_MD
#include <stm32f10x.h>
#endif

Time now;

#ifdef STM32F10X_MD
extern "C"
void SysTick_Handler() {
	Time::tick();
}

void Time::tick() {
	static uint32_t rtcLast = 0;
	uint32_t rtcNow = RTC_GetCounter();

	if (rtcLast != rtcNow) {
		::now.msec = 0;
		::now.sec = rtcNow;
		rtcLast = rtcNow;
	} else if (::now.msec != 999) {
		// don't allow an invalid msec value, wait for RTC sync instead
		::now.msec++;
	}
}
#endif

Time::Time() {
	sec = 0;
	msec = 0;
	usec = 0;
}

Time::Time(uint32_t sec, uint16_t msec, uint16_t usec) :
		sec(sec), msec(msec), usec(usec) {
}

Time Time::now() {
#ifndef STM32F10X_MD
	::now.addMsec(16);
#endif
	return ::now;
}

#ifdef STM32F10X_MD
/**
 * returns current time with  'usec precision'
 * @note not that precise but now() returns with .usec being 0
 */
Time Time::preciseNow() {
	Time t1, t2;
	uint32_t systickVal;
	do {
		// this loop makes sure that systickVal and t1 (and t2) are consistent (SysTick IRQ did not happen between t1 and systickVal setting)
		t1 = ::now;
		systickVal = SysTick->VAL;
		t2 = ::now;
	} while (t1.msec != t2.msec);	// comparing ms in enough, since ::now is updated atomically (in interrupt context)
	t1.usec = (systickVal * 1000) / SystemCoreClock;
	return t1;
}
#endif

void Time::addMsec(uint16_t msec) {
	this->msec += msec;
	this->normalize();
}

bool Time::operator>(const Time& other) const {
	if (sec > other.sec) {
		return true;
	} else if (sec == other.sec) {
		if (msec > other.msec) {
			return true;
		} else if (msec == other.msec) {
			if (usec > other.usec) {
				return true;
			}
		}
	}
	return false;
}

bool Time::operator<(const Time& other) const {
	return (*this > other);
}

uint32_t Time::toMsec() const {
	return sec * 1000 + msec;
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
