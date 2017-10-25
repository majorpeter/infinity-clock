/*
 * EventLoop.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "EventLoop.h"
#include "Canvas.h"
#include "qep/Qep.h"
#include "FunctionButton.h"

#include <mprotocol-server/ProtocolParser.h>
#include <stddef.h>

EventLoop::EventLoop(Canvas& canvas, Qep& qep, FunctionButton& button,
        ProtocolParser* protocolParser, StateMachine* initialState) :
        canvas(canvas), qep(qep), button(button),
        protocolParser(protocolParser), state(initialState) {
}

void EventLoop::run() {
    this->enter(state);
    while (1) {
        Time now = Time::now();
        qep.update();
        button.update();
        StateMachine* nextState = state->update(qep, button, now);
        if (nextState != state) {
            enter(nextState);
        }
        state->render(canvas, now);
        canvas.draw();

        protocolParser->handler();
    }
}

void EventLoop::enter(StateMachine* nextState) {
    if (state != NULL) {
        state->onLeave();
    }
    state = nextState;
    state->onEnter();
}
