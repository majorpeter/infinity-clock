/*
 * EventLoop.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef EVENTLOOP_H_
#define EVENTLOOP_H_

#include "StateMachine.h"

class EventLoop {
public:
	EventLoop(Canvas& canvas, StateMachine* defaultState, StateMachine* initialState);
	~EventLoop() {}
	void run();
private:
	Canvas& canvas;
	StateMachine* defaultState;
	StateMachine* initialState;
	StateMachine* currentState;

	void enter(StateMachine* nextState);
};

#endif /* EVENTLOOP_H_ */
