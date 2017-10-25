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
class ProtocolParser;

class EventLoop {
public:
    EventLoop(Canvas& canvas, Qep& qep, FunctionButton& button, ProtocolParser* protocolParser, StateMachine* initialState);
    ~EventLoop() {}
    void run();
private:
    Canvas& canvas;
    Qep& qep;
    FunctionButton& button;

    ProtocolParser* protocolParser;
    StateMachine* state;

    void enter(StateMachine* nextState);
};

#endif /* EVENTLOOP_H_ */
