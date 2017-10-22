/*
 * StateMachineInitial.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_Initial.h"
#include "Canvas.h"
#include "FunctionButton.h"

static const Time renderTime = {5, 0};

StateMachine_Initial::StateMachine_Initial() {
}

void StateMachine_Initial::onEnter() {
    enterTime = Time::now();
}

StateMachine::Result StateMachine_Initial::update(const Qep&, const FunctionButton& button, const Time& now) {
    if (now.toMsec() - enterTime.toMsec() > renderTime.toMsec()) {
        return Result_Done;
    }
    if (button.getEvent() != FunctionButton::Event::None) {
        return Result_Done;
    }
    return Result_Ok;
}

void StateMachine_Initial::render(Canvas& canvas, const Time& now) {
    uint8_t status = 0;
    uint32_t runTime = now.toMsec() - enterTime.toMsec();
    if (runTime <= renderTime.toMsec() / 2) {
        status = runTime * 0xff / renderTime.toMsec() * 2;
    } else {
        status = 0xff - (runTime - renderTime.toMsec() / 2) * 0xff / renderTime.toMsec() * 2;
    }
    canvas.fillColor(Color(status, status, status));
}
