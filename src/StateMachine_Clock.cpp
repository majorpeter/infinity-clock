/*
 * StateMachine_Clock.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_Clock.h"
#include "Canvas.h"

static const uint16_t secondAnimationDurationMs = 300;
static const uint16_t minuteAnimationDurationMs = 1200;
static const uint16_t hourAnimationDurationMs = 2800;

// there are 60 leds, and 12 hours
static const uint8_t ledsPerHour = (60 / 12);

StateMachine_Clock::StateMachine_Clock() {
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
	uint8_t hour = (now.getSec() / 3600) % 12;
	uint8_t minute = (now.getSec() / 60) % 60;
	uint8_t second = now.getSec() % 60;
	uint16_t millisec = now.getMsec();

	canvas.fillColor(Color::black);

	uint16_t minuteAnimationMs = second * 1000 + millisec;
	int16_t hourCenterLedIndex = hour * ledsPerHour;
	if ((minute == 0) && (minuteAnimationMs < hourAnimationDurationMs)) {
		// [0 -> 1.0] transition state
		float animState = (float) minuteAnimationMs / hourAnimationDurationMs;
		// [0 .. 5], hourCenterLedIndex will be added to it
		float centerPositionOffset = (1.f - animState) * ledsPerHour;
		int16_t centerPositionOffsetIndex = (int16_t) centerPositionOffset;
		float animationDifference = centerPositionOffset - centerPositionOffsetIndex;

		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex - 2, Color::red * animationDifference);
		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex - 1, Color::red);
		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex, Color::red);
		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex + 1, Color::red * (1.f - animationDifference));
	} else {
		canvas.add(hourCenterLedIndex - 1, Color::red);
		canvas.add(hourCenterLedIndex, Color::red);
		canvas.add(hourCenterLedIndex + 1, Color::red);
	}

	if (minuteAnimationMs < minuteAnimationDurationMs) {
		float animState = (float) minuteAnimationMs / minuteAnimationDurationMs;
		canvas.add(minute - 1, Color::green * (1.f - animState));
		canvas.add(minute, Color::green * animState);
	} else {
		canvas.add(minute, Color::green);
	}

	if (millisec < secondAnimationDurationMs) {
		float animState = ((float) millisec / (secondAnimationDurationMs));
		canvas.add(second - 1, Color::blue * (1.f - animState));
		canvas.add(second, Color::blue * animState);
	} else {
		canvas.add(second, Color::blue);
	}
}
