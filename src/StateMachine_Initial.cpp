/*
 * StateMachineInitial.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_Initial.h"
#include "Canvas.h"

static const Time renderTime = {5, 0, 0};

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
	uint8_t status = 0;
	if (now.toMsec() <= renderTime.toMsec() / 2) {
		status = now.toMsec() * 0xff / renderTime.toMsec() * 2;
	} else {
		status = 0xff - (now.toMsec() - renderTime.toMsec() / 2) * 0xff / renderTime.toMsec() * 2;
	}
	canvas.fillColor(Color(status, status, status));
}
