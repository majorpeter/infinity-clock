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

#include <stddef.h>

EventLoop::EventLoop(Canvas& canvas, Qep& qep, FunctionButton& button,
        StateMachine* defaultState, StateMachine* initialState) :
        canvas(canvas), qep(qep), button(button), defaultState(defaultState), initialState(initialState) {
    if (initialState == NULL) {
        this->initialState = defaultState;
    }
    currentState = NULL;
}

void EventLoop::run() {
    this->enter(initialState);
    while (1) {
        Time now = Time::now();
        qep.update();
        button.update();
        StateMachine::Result r = this->currentState->update(qep, button, now);
        switch (r) {
        case StateMachine::Result_Done:
            this->enter(defaultState);
            continue;
        default:
            break;
        }
        this->currentState->render(canvas, now);
        this->canvas.draw();
    }
}

void EventLoop::enter(StateMachine* nextState) {
    if (currentState != NULL) {
        currentState->onLeave();
    }
    currentState = nextState;
    currentState->onEnter();
}
