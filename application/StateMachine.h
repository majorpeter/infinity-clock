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
class Qep;
class FunctionButton;

class StateMachine {
public:
    StateMachine() {}
    virtual ~StateMachine() {}

    virtual void onEnter() {}
    virtual void onLeave() {}

    virtual StateMachine* update(const Qep& qep, const FunctionButton& button, const Time& now) = 0;
    virtual void render(Canvas& canvas, const Time& now) {}
};

#endif /* STATEMACHINE_H_ */
