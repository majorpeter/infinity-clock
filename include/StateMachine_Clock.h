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

class Layer;

class StateMachine_Clock: public StateMachine {
public:
    StateMachine_Clock(const Color colorHour, const Color colorMinute,
            const Color colorSecond, const Color colorCardinalDirections);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Layer* layers[3];

    /// The four cardinal directions or cardinal points are the directions north, east, south, and west
    const Color colorCardinalDirections;
};

#endif /* STATEMACHINE_CLOCK_H_ */
