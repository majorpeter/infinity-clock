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
#include "layers/ClockProximityMarker.h"

using namespace Layers;

StateMachine_Clock::StateMachine_Clock(const Color colorHour,
        const Color colorMinute, const Color colorSecond,
        const Color colorCardinalDirections,
        const Color colorProximityMarkers) {
    layers[0] = new ClockHour(colorHour);
    layers[1] = new ClockMinute(colorMinute);
    layers[2] = new ClockSecond(colorSecond);

    // The four cardinal directions or cardinal points are the directions north, east, south, and west
    layers[3] = new ClockMarker(colorCardinalDirections, 0);
    layers[4] = new ClockMarker(colorCardinalDirections, 15);
    layers[5] = new ClockMarker(colorCardinalDirections, 30);
    layers[6] = new ClockMarker(colorCardinalDirections, 45);

    static const uint8_t proximity = 3;
    layers[7] = new ClockProximityMarker(colorProximityMarkers, 5, proximity);
    layers[8] = new ClockProximityMarker(colorProximityMarkers, 10, proximity);
    layers[9] = new ClockProximityMarker(colorProximityMarkers, 20, proximity);
    layers[10] = new ClockProximityMarker(colorProximityMarkers, 25, proximity);
    layers[11] = new ClockProximityMarker(colorProximityMarkers, 35, proximity);
    layers[12] = new ClockProximityMarker(colorProximityMarkers, 40, proximity);
    layers[13] = new ClockProximityMarker(colorProximityMarkers, 50, proximity);
    layers[14] = new ClockProximityMarker(colorProximityMarkers, 55, proximity);
}

void StateMachine_Clock::render(Canvas& canvas, const Time& now) {
    canvas.fillColor(Color::black);

    for (uint8_t i = 0; i < sizeof(layers) / sizeof(layers[0]); i++) {
        layers[i]->render(canvas, now);
    }
}
