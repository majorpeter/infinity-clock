/*
 * StateMachine_Clock.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_ClockSetup.h"
#include "StateMachine_Clock.h"
#include "Canvas.h"

#include "layers/ClockHour.h"
#include "layers/ClockMinute.h"
#include "layers/ClockSecond.h"
#include "layers/ClockMarker.h"

#include "qep/Qep.h"
#include "FunctionButton.h"

#include <stddef.h>
#include <math.h>

StateMachine_ClockSetup* StateMachine_ClockSetup::instance = NULL;

using namespace Layers;

StateMachine_ClockSetup::StateMachine_ClockSetup(Layers::ClockLayerCollection* layers) :
        layers(layers) {
    instance = this;
    qepAbsValue = 0;
    state = State::HourSetting;
}

StateMachine_ClockSetup* StateMachine_ClockSetup::getInstance() {
    return instance;
}

void StateMachine_ClockSetup::onEnter() {
    timeToSet = Time::now();
    state = State::HourSetting;
}

StateMachine* StateMachine_ClockSetup::update(const Qep& qep, const FunctionButton& button, const Time& now) {
    // this particular encoder has to be scaled down
    int32_t qepAbsValue = qep.getAbsolutePosition() / 2;
    int32_t qepStep = qepAbsValue - this->qepAbsValue;
    this->qepAbsValue = qepAbsValue;

    if (qepStep != 0) {
        switch (state) {
        case State::HourSetting:
            timeToSet.addSec((qepStep > 0) ? 3600 : -3600);
            break;
        case State::MinuteSetting:
            timeToSet.addSec((qepStep > 0) ? 60 : -60);
            break;
        case State::SecondSetting:
            timeToSet.addSec((qepStep > 0) ? 1 : -1);
            break;
        }
    }

    if (button.getEvent() == FunctionButton::Event::ShortPress) {
        switch (state) {
        case State::HourSetting:
            state = State::MinuteSetting;
            break;
        case State::MinuteSetting:
            state = State::SecondSetting;
            break;
        case State::SecondSetting:
            return StateMachine_Clock::getInstance();
        }
    }

    return this;
}

void StateMachine_ClockSetup::render(Canvas& canvas, const Time& now) {
    canvas.fillColor(Color::black);

    float currentLayerBrightness = abs(now.getMsec() - 500) / 500.f;

    layers->hour->render(canvas, timeToSet, (state == State::HourSetting) ? currentLayerBrightness : 1.f);
    if (state > State::HourSetting) {
        layers->minute->render(canvas, timeToSet, (state == State::MinuteSetting) ? currentLayerBrightness : 1.f);
        if (state > State::MinuteSetting) {
            layers->second->render(canvas, timeToSet, currentLayerBrightness);
        }
    }

    for (uint8_t i = 0; i < sizeof(layers->markers) / sizeof(layers->markers[0]); i++) {
        layers->markers[i]->render(canvas, now);
    }
}
