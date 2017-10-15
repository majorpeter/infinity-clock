/*
 * StateMachine_Clock.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_Clock.h"
#include "Canvas.h"

static const uint16_t secondAnimationDurationMs = 300;
static const uint16_t minuteAnimationDurationMs = 1400;

StateMachine_Clock::StateMachine_Clock() {
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
	uint8_t hour = (now.getSec() / 3600) % 12;
	uint8_t min = (now.getSec() / 60) % 60;
	uint8_t sec = now.getSec() % 60;
	uint16_t ms = now.getMsec();

	canvas.fillColor(Color::black);

	int16_t hour_m1_led_index = hour * 5 - 1;
	canvas.add(hour_m1_led_index, Color::red);
	canvas.add(hour * 5, Color::red);
	canvas.add(hour * 5 + 1, Color::red);

	uint16_t minuteAnimationMs = sec * 1000 + ms;
	if (minuteAnimationMs < minuteAnimationDurationMs) {
		float animState = (float) minuteAnimationMs / minuteAnimationDurationMs;
		canvas.add(min - 1, Color::green * (1.f - animState));
		canvas.add(min, Color::green * animState);
	} else {
		canvas.add(min, Color::green);
	}

	if (ms < secondAnimationDurationMs) {
		float animState = ((float) ms / (secondAnimationDurationMs));
		canvas.add(sec - 1, Color::blue * (1.f - animState));
		canvas.add(sec, Color::blue * animState);
	} else {
		canvas.add(sec, Color::blue);
	}
}
