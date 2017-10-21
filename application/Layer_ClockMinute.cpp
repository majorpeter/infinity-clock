/*
 * Layer_ClockMinute.cpp
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#include "Layer_ClockMinute.h"

static const uint16_t minuteAnimationDurationMs = 1200;

Layer_ClockMinute::Layer_ClockMinute(const Color color) : color(color) {
}

void Layer_ClockMinute::render(Canvas& canvas, const Time& now) {
    uint8_t second = now.getSec() % 60;
    uint8_t minute = (now.getSec() / 60) % 60;

    uint16_t minuteAnimationMs = second * 1000 + now.getMsec();
    if (minuteAnimationMs < minuteAnimationDurationMs) {
        float animState = (float) minuteAnimationMs / minuteAnimationDurationMs;
        canvas.add(minute - 1, color * (1.f - animState));
        canvas.add(minute, color * animState);
    } else {
        canvas.add(minute, color);
    }
}
