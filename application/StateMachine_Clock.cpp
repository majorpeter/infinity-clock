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

using namespace Layers;

StateMachine_Clock::StateMachine_Clock(const Color colorHour,
        const Color colorMinute, const Color colorSecond,
        const Color colorCardinalDirections) :
        colorCardinalDirections(colorCardinalDirections) {
    layers[0] = new ClockHour(colorHour);
    layers[1] = new ClockMinute(colorMinute);
    layers[2] = new ClockSecond(colorSecond);
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
    canvas.fillColor(Color::black);

    for (uint8_t i = 0; i < sizeof(layers) / sizeof(layers[0]); i++) {
        layers[i]->render(canvas, now);
    }

    if (!canvas.isSet(0)) {
        canvas.set(0, colorCardinalDirections);
    }
    if (!canvas.isSet(15)) {
        canvas.set(15, colorCardinalDirections);
    }
    if (!canvas.isSet(30)) {
        canvas.set(30, colorCardinalDirections);
    }
    if (!canvas.isSet(45)) {
        canvas.set(45, colorCardinalDirections);
    }
}
