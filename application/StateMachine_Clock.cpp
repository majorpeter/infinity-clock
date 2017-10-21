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

StateMachine_Clock::StateMachine_Clock(const Color colorHour,
        const Color colorMinute, const Color colorSecond,
        const Color colorCardinalDirections) {
    layers[0] = new ClockHour(colorHour);
    layers[1] = new ClockMinute(colorMinute);
    layers[2] = new ClockSecond(colorSecond);

    // The four cardinal directions or cardinal points are the directions north, east, south, and west
    layers[3] = new ClockMarker(colorCardinalDirections, 0);
    layers[4] = new ClockMarker(colorCardinalDirections, 15);
    layers[5] = new ClockMarker(colorCardinalDirections, 30);
    layers[6] = new ClockMarker(colorCardinalDirections, 45);
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
    canvas.fillColor(Color::black);

    for (uint8_t i = 0; i < sizeof(layers) / sizeof(layers[0]); i++) {
        layers[i]->render(canvas, now);
    }
}
