/*
 * StateMachine_Clock.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef STATEMACHINE_CLOCK_H_
#define STATEMACHINE_CLOCK_H_

#include "Color.h"
#include "StateMachine.h"

class Layer;

class StateMachine_Clock: public StateMachine {
public:
    StateMachine_Clock(const Color colorHour, const Color colorMinute,
            const Color colorSecond, const Color colorCardinalDirections);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Layer* layers[7];
};

#endif /* STATEMACHINE_CLOCK_H_ */
