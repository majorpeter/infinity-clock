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
	canvas.set(hour * 5 - 1, Color(255, 0, 0));
	canvas.set(hour * 5, Color(255, 0, 0));
	canvas.set(hour * 5 + 1, Color(255, 0, 0));

	canvas.set(min, Color(0, 255, 0));
	canvas.set(sec, Color(0, 0, 255));
}
