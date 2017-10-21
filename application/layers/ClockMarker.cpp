/*
 * ClockMarker.cpp
 *
 *  Created on: 2017. okt. 21.
 *      Author: peti
 */

#include "ClockMarker.h"

#define DEBUG_PRINTF(...)

namespace Layers {

static const uint16_t fadeTimeMs = 400;

ClockMarker::ClockMarker(Color color, uint8_t ledIndex) :
        color(color), ledIndex(ledIndex) {
    state = State::Hidden;
    animationStartMs = 0;
}

void ClockMarker::render(Canvas& canvas, const Time& now) {
    switch (state) {
    case State::Hidden:
        if (shouldBeVisible(canvas)) {
            state = State::FadeIn;
            animationStartMs = now.toMsec();
        }
        break;
    case State::Default:
        if (!shouldBeVisible(canvas)) {
            state = State::FadeOut;
            animationStartMs = now.toMsec();
        }
        canvas.add(ledIndex, color);
        break;
    case State::FadeIn: {
        float animationState = (now.toMsec() - animationStartMs) / (float) fadeTimeMs;
        if (animationState > 1.f) {
            animationState = 1.f;
            state = State::Default;
        }
        DEBUG_PRINTF("LED#%hhu anim_in %f\n", ledIndex, animationState);
        canvas.add(ledIndex, color * animationState);
        break;
    }
    case State::FadeOut: {
        float animationState = (now.toMsec() - animationStartMs) / (float) fadeTimeMs;
        if (animationState > 1.f) {
            animationState = 1.f;
            state = State::Hidden;
        }
        DEBUG_PRINTF("LED#%hhu anim_out %f\n", ledIndex, animationState);
        canvas.add(ledIndex, color * (1.f - animationState));
        break;
    }
    }
}

bool ClockMarker::shouldBeVisible(Canvas& canvas) {
    return !canvas.isSet(ledIndex);
}

} /* namespace Layers */
