/*
 * Layer_ClockMinute.cpp
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#include "ClockMinute.h"

namespace Layers {

static const uint16_t minuteAnimationDurationMs = 1200;

ClockMinute::ClockMinute(const Color color) : color(color) {
}

void ClockMinute::render(Canvas& canvas, const Time& now, float brightness) {
    uint8_t second = now.getSec() % 60;
    uint8_t minute = (now.getSec() / 60) % 60;

    Color color = this->color * brightness;
    uint16_t minuteAnimationMs = second * 1000 + now.getMsec();
    if (minuteAnimationMs < minuteAnimationDurationMs) {
        float animState = (float) minuteAnimationMs / minuteAnimationDurationMs;
        canvas.add(minute - 1, color * (1.f - animState));
        canvas.add(minute, color * animState);
    } else {
        canvas.add(minute, color);
    }
}

} /* namespace Layers */
