/*
 * StateMachine_Clock.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_Clock.h"
#include "Canvas.h"

StateMachine_Clock::StateMachine_Clock() {
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
	uint8_t hour = now.getSec() / 3600;
	uint8_t min = (now.getSec() / 60) % 60;
	uint8_t sec = now.getSec() % 60;

	canvas.fillColor(Color(0,0,0));
	int16_t hour_m1_led_index = hour * 5 - 1;
	canvas.set((hour_m1_led_index < 0) ? (hour_m1_led_index + 60) : hour_m1_led_index, Color::red);
	canvas.set(hour * 5, Color::red);
	canvas.set(hour * 5 + 1, Color::red);

	canvas.set(min, Color::green);
	canvas.set(sec, Color::blue);
}
