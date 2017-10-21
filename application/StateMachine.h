/*
 * StateMachine.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "Time.h"

class Canvas;

class StateMachine {
public:
    typedef enum {
        /// return this for normal operation
        Result_Ok,
        /// return this to return to default state
        Result_Done
    } Result;

    StateMachine() {}
    virtual ~StateMachine() {}

    virtual void onEnter() {}
    virtual void onLeave() {}

    virtual StateMachine::Result update(const Time& now) {
        return Result_Ok;
    }
    virtual void render(Canvas& canvas, const Time& now) {}
};

#endif /* STATEMACHINE_H_ */
