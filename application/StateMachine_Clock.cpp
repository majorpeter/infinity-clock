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

using namespace Layers;

StateMachine_Clock::StateMachine_Clock(Layers::ClockLayerCollection* layers) :
        layers(layers) {
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
    canvas.fillColor(Color::black);

    layers->hour->render(canvas, now);
    layers->minute->render(canvas, now);
    layers->second->render(canvas, now);
    for (uint8_t i = 0; i < sizeof(layers->markers) / sizeof(layers->markers[0]); i++) {
        layers->markers[i]->render(canvas, now);
    }
}
