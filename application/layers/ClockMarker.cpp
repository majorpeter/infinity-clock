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

/**
 * @param color marker color when visible
 * @param ledIndex position on the clock face
 */
ClockMarker::ClockMarker(Color color, uint8_t ledIndex) :
        ledIndex(ledIndex), color(color) {
    state = State::Hidden;
    animationStartMs = 0;
}

void ClockMarker::render(Canvas& canvas, const Time& now) {
    switch (state) {
    case State::Hidden:
        if (shouldBeVisible(canvas)) {
            this->show(now);
        }
        break;
    case State::Default:
        if (!shouldBeVisible(canvas)) {
            this->hide(now);
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

void ClockMarker::hide(const Time& now) {
    state = State::FadeOut;
    animationStartMs = now.toMsec();
}

void ClockMarker::show(const Time& now) {
    state = State::FadeIn;
    animationStartMs = now.toMsec();
}

bool ClockMarker::shouldBeVisible(Canvas& canvas) {
    return !canvas.isSet(ledIndex);
}

} /* namespace Layers */
