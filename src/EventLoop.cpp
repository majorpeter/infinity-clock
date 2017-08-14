/*
 * EventLoop.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "EventLoop.h"
#include "Canvas.h"
#include <stddef.h>

EventLoop::EventLoop(Canvas& canvas, StateMachine* defaultState,
		StateMachine* initialState) :
		canvas(canvas), defaultState(defaultState), initialState(initialState) {
	currentState = NULL;
}

void EventLoop::run() {
	this->enter(initialState);
	while (1) {
		Time now = Time::now();
		StateMachine::Result r = this->currentState->update(now);
		switch (r) {
		case StateMachine::Result_Done:
			this->enter(defaultState);
			continue;
		default:
			break;
		}
		this->currentState->render(canvas, now);
		this->canvas.draw();
	}
}

void EventLoop::enter(StateMachine* nextState) {
	if (currentState != NULL) {
		currentState->onLeave();
	}
	currentState = nextState;
	currentState->onEnter();
}
