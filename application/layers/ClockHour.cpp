/*
 * LayerClock_Hour.cpp
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#include "ClockHour.h"

namespace Layers {

static const uint16_t hourAnimationDurationMs = 2800;

// there are 60 leds, and 12 hours
static const uint8_t ledsPerHour = (60 / 12);

ClockHour::ClockHour(Color color) : color(color) {
}

void ClockHour::render(Canvas& canvas, const Time& now) {
    uint8_t hour = (now.getSec() / 3600) % 12;
    uint8_t minute = (now.getSec() / 60) % 60;
    uint8_t second = now.getSec() % 60;

    uint16_t hourAnimationMs = second * 1000 + now.getMsec();
    int16_t hourCenterLedIndex = hour * ledsPerHour;
    if ((minute == 0) && (hourAnimationMs < hourAnimationDurationMs)) {
        // [0 -> 1.0] transition state
        float animState = (float) hourAnimationMs / hourAnimationDurationMs;
        // [0 .. 5], hourCenterLedIndex will be added to it
        float centerPositionOffset = (1.f - animState) * ledsPerHour;
        int16_t centerPositionOffsetIndex = (int16_t) centerPositionOffset;
        float animationDifference = centerPositionOffset - centerPositionOffsetIndex;

        canvas.add(hourCenterLedIndex - centerPositionOffsetIndex - 2, color * animationDifference);
        canvas.add(hourCenterLedIndex - centerPositionOffsetIndex - 1, color);
        canvas.add(hourCenterLedIndex - centerPositionOffsetIndex, color);
        canvas.add(hourCenterLedIndex - centerPositionOffsetIndex + 1, color * (1.f - animationDifference));
    } else {
        canvas.add(hourCenterLedIndex - 1, color);
        canvas.add(hourCenterLedIndex, color);
        canvas.add(hourCenterLedIndex + 1, color);
    }

}

} /* namespace Layers */
