/*
 * FunctionButton.cpp
 *
 *  Created on: 2017. okt. 22.
 *      Author: peti
 */

#include "FunctionButton.h"
#include "Time.h"

static const uint16_t longPressTimeMs = 600;

FunctionButton::FunctionButton(GPIO_TypeDef * const port, uint16_t pin): port(port), pin(pin) {
    pinValue = 0;
    event = Event::None;
    pressStartMs = 0;
}

void FunctionButton::init() {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStruct.GPIO_Pin = pin;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(port, &GPIO_InitStruct);
}

void FunctionButton::update() {
    uint8_t pinValue = GPIO_ReadInputDataBit(port, pin);
    if (pinValue != this->pinValue) {
        if (pinValue) {
            // pressed
            pressStartMs = Time::now().toMsec();
            event = Event::None;
        } else {
            uint32_t pressTimeMs = Time::now().toMsec() - pressStartMs;
            if (pressTimeMs >= longPressTimeMs) {
                event = Event::LongPress;
            } else {
                event = Event::ShortPress;
            }
        }
        this->pinValue = pinValue;
    }
}
