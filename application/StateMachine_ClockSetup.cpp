/*
 * StateMachine_Clock.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_ClockSetup.h"
#include "Canvas.h"

#include "layers/ClockHour.h"
#include "layers/ClockMinute.h"
#include "layers/ClockSecond.h"
#include "layers/ClockMarker.h"

#include "qep/Qep.h"

#include <stddef.h>

StateMachine_ClockSetup* StateMachine_ClockSetup::instance = NULL;

using namespace Layers;

StateMachine_ClockSetup::StateMachine_ClockSetup(Layers::ClockLayerCollection* layers) :
        layers(layers) {
    instance = this;
    state = State::Hour;
}

StateMachine_ClockSetup* StateMachine_ClockSetup::getInstance() {
    return instance;
}

void StateMachine_ClockSetup::onEnter() {
    timeToSet = Time::now();
    state = State::Hour;
}

StateMachine* StateMachine_ClockSetup::update(const Qep& qep, const FunctionButton& button, const Time& now) {
    return this;
}

void StateMachine_ClockSetup::render(Canvas& canvas, const Time& now) {
    canvas.fillColor(Color::black);

    layers->hour->render(canvas, timeToSet);
    layers->minute->render(canvas, timeToSet);
    layers->second->render(canvas, timeToSet);

    for (uint8_t i = 0; i < sizeof(layers->markers) / sizeof(layers->markers[0]); i++) {
        layers->markers[i]->render(canvas, now);
    }
}
