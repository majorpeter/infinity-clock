/*
 * StateMachine_Clock.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef STATEMACHINE_CLOCK_H_
#define STATEMACHINE_CLOCK_H_

#include "StateMachine.h"

class StateMachine_Clock: public StateMachine {
public:
	StateMachine_Clock();
	virtual void render(Canvas& canvas, const Time& now);
};

#endif /* STATEMACHINE_CLOCK_H_ */
