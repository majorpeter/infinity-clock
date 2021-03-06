/*
 * Layer_ClockSecond.cpp
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#include "ClockSecond.h"

namespace Layers {

static const uint16_t secondAnimationDurationMs = 300;

ClockSecond::ClockSecond(const Color color) : color(color) {
}

void ClockSecond::render(Canvas& canvas, const Time& now, float brightness) {
    uint8_t second = now.getSec() % 60;
    uint16_t millisec = now.getMsec();

    Color color = this->color * brightness;
    if (millisec < secondAnimationDurationMs) {
        float animState = ((float) millisec / (secondAnimationDurationMs));
        canvas.add(second - 1, color * (1.f - animState));
        canvas.add(second, color * animState);
    } else {
        canvas.add(second, color);
    }
}

} /* namespace Layers */
