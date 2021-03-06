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
volatile uint32_t ticksSinceStart;

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
    ticksSinceStart++;
}

uint32_t Time::getTicksSinceStart() {
    return ticksSinceStart;
}
#endif

Time::Time() {
    sec = 0;
    msec = 0;
}

Time::Time(uint32_t sec, uint16_t msec) :
        sec(sec), msec(msec) {
}

Time Time::now() {
#ifndef STM32F10X_MD
    ::now.addMsec(16);
#endif
    return ::now;
}

void Time::setNow(const Time& value) {
#ifdef STM32F10X_MD
    PWR_BackupAccessCmd(ENABLE);
    RTC_WaitForLastTask();
    RTC_SetCounter(value.sec);
    RTC_WaitForLastTask();
    PWR_BackupAccessCmd(DISABLE);

#endif
    ::now = value;
}

void Time::addSec(int32_t sec) {
    int32_t result = this->sec + sec;
    if (result < 0) {
        result += 12 * 3600;
    }
    this->sec = result;
}

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
        }
    }
    return false;
}

bool Time::operator<(const Time& other) const {
    return (*this > other);
}

void Time::normalize() {
    if (msec >= 1000) {
        sec += msec / 1000;
        msec %= 1000;
    }
}
