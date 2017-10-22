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
        StateMachine* initialState) :
        canvas(canvas), qep(qep), button(button), state(initialState) {
}

void EventLoop::run() {
    this->enter(state);
    while (1) {
        Time now = Time::now();
        qep.update();
        button.update();
        StateMachine* nextState = this->state->update(qep, button, now);
        if (nextState != state) {
            this->enter(nextState);
        }
        this->state->render(canvas, now);
        this->canvas.draw();
    }
}

void EventLoop::enter(StateMachine* nextState) {
    if (state != NULL) {
        state->onLeave();
    }
    state = nextState;
    state->onEnter();
}
