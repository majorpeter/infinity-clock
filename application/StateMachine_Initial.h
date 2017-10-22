/*
 * StateMachineInitial.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef STATEMACHINE_INITIAL_H_
#define STATEMACHINE_INITIAL_H_

#include "StateMachine.h"
#include "Time.h"

class StateMachine_Initial: public StateMachine {
public:
    StateMachine_Initial();
    virtual void onEnter();
    virtual Result update(const Qep& qep, const Time& now);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Time enterTime;
};

#endif /* STATEMACHINE_INITIAL_H_ */
