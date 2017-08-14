/*
 * StateMachineInitial.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_Initial.h"
#include "Canvas.h"

static const Time renderTime = {2, 0, 0};

StateMachine_Initial::StateMachine_Initial() {
}

void StateMachine_Initial::onEnter() {
	enterTime = Time::now();
}

StateMachine::Result StateMachine_Initial::update(const Time& now) {
	if (now > renderTime) {
		return Result_Done;
	}
	return Result_Ok;
}

void StateMachine_Initial::render(Canvas& canvas, const Time& now) {
	uint8_t status = now.toMsec() * 0xff / renderTime.toMsec();
	canvas.fillColor(Color(status, status, status));
}
