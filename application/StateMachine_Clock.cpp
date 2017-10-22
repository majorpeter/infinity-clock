/*
 * StateMachine_Clock.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "StateMachine_Clock.h"
#include "Canvas.h"

#include "layers/ClockHour.h"
#include "layers/ClockMinute.h"
#include "layers/ClockSecond.h"
#include "layers/ClockMarker.h"

#include "qep/Qep.h"

using namespace Layers;

StateMachine_Clock::StateMachine_Clock(Layers::ClockLayerCollection* layers) :
        layers(layers) {
    brightness = 1.f;
}

StateMachine::Result StateMachine_Clock::update(const Qep& qep, const FunctionButton& button, const Time& now) {
    static const float minimumVisibleValue = 0.05f;
    int32_t qepStep = qep.getDeltaValue();
    if (qepStep < 0) {
        brightness *= 0.7f;
        if (brightness < minimumVisibleValue) {
            brightness = 0.f;
        }
    }
    else if (qepStep > 0) {
        if (brightness == 0.f) {
            brightness = minimumVisibleValue;
        } else {
            brightness *= 1.3f;
            if (brightness > 1.f) {
                brightness = 1.f;
            }
        }
    }

    return StateMachine::Result_Ok;
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
    canvas.fillColor(Color::black);

    layers->hour->render(canvas, now, brightness);
    layers->minute->render(canvas, now, brightness);
    layers->second->render(canvas, now, brightness);
    for (uint8_t i = 0; i < sizeof(layers->markers) / sizeof(layers->markers[0]); i++) {
        layers->markers[i]->render(canvas, now, brightness);
    }
}
