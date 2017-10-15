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

StateMachine_Clock::StateMachine_Clock(const Color colorHour,
		const Color colorMinute, const Color colorSecound,
		const Color colorCardinalDirections) :
		colorHour(colorHour), colorMinute(colorMinute),
		colorSecound(colorSecound), colorCardinalDirections(colorCardinalDirections) {
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

		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex - 2, colorHour * animationDifference);
		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex - 1, colorHour);
		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex, colorHour);
		canvas.add(hourCenterLedIndex - centerPositionOffsetIndex + 1, colorHour * (1.f - animationDifference));
	} else {
		canvas.add(hourCenterLedIndex - 1, colorHour);
		canvas.add(hourCenterLedIndex, colorHour);
		canvas.add(hourCenterLedIndex + 1, colorHour);
	}

	if (minuteAnimationMs < minuteAnimationDurationMs) {
		float animState = (float) minuteAnimationMs / minuteAnimationDurationMs;
		canvas.add(minute - 1, colorMinute * (1.f - animState));
		canvas.add(minute, colorMinute * animState);
	} else {
		canvas.add(minute, colorMinute);
	}

	if (millisec < secondAnimationDurationMs) {
		float animState = ((float) millisec / (secondAnimationDurationMs));
		canvas.add(second - 1, colorSecound * (1.f - animState));
		canvas.add(second, colorSecound * animState);
	} else {
		canvas.add(second, colorSecound);
	}

	if (!canvas.isSet(0)) {
		canvas.set(0, colorCardinalDirections);
	}
	if (!canvas.isSet(15)) {
		canvas.set(15, colorCardinalDirections);
	}
	if (!canvas.isSet(30)) {
		canvas.set(30, colorCardinalDirections);
	}
	if (!canvas.isSet(45)) {
		canvas.set(45, colorCardinalDirections);
	}
}
