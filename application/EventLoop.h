/*
 * EventLoop.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef EVENTLOOP_H_
#define EVENTLOOP_H_

#include "StateMachine.h"

class Qep;
class FunctionButton;

class EventLoop {
public:
    EventLoop(Canvas& canvas, Qep& qep, FunctionButton& button, StateMachine* initialState);
    ~EventLoop() {}
    void run();
private:
    Canvas& canvas;
    Qep& qep;
    FunctionButton& button;

    StateMachine* state;

    void enter(StateMachine* nextState);
};

#endif /* EVENTLOOP_H_ */
