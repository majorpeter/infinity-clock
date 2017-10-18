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
    StateMachine_Clock(const Color colorHour, const Color colorMinute,
            const Color colorSecound, const Color colorCardinalDirections);
    virtual void render(Canvas& canvas, const Time& now);
private:
    const Color colorHour;
    const Color colorMinute;
    const Color colorSecound;
    /// The four cardinal directions or cardinal points are the directions north, east, south, and west
    const Color colorCardinalDirections;
};

#endif /* STATEMACHINE_CLOCK_H_ */
