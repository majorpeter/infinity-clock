/*
 * Layer_ClockSecond.cpp
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#include "Layer_ClockSecond.h"

static const uint16_t secondAnimationDurationMs = 300;

Layer_ClockSecond::Layer_ClockSecond(const Color color) : color(color) {
}

void Layer_ClockSecond::render(Canvas& canvas, const Time& now) {
    uint8_t second = now.getSec() % 60;
    uint16_t millisec = now.getMsec();

    if (millisec < secondAnimationDurationMs) {
        float animState = ((float) millisec / (secondAnimationDurationMs));
        canvas.add(second - 1, color * (1.f - animState));
        canvas.add(second, color * animState);
    } else {
        canvas.add(second, color);
    }
}
