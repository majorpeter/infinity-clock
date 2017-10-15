/*
 * StateMachine_Clock.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef STATEMACHINE_CLOCK_H_
#define STATEMACHINE_CLOCK_H_

#include "StateMachine.h"
#include "Color.h"

class StateMachine_Clock: public StateMachine {
public:
	StateMachine_Clock(const Color& colorHour, const Color& colorMinute,
			const Color& colorSecound);
	virtual void render(Canvas& canvas, const Time& now);
private:
	const Color colorHour;
	const Color colorMinute;
	const Color colorSecound;
};

#endif /* STATEMACHINE_CLOCK_H_ */
