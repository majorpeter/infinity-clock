/*
 * ClockProximityMarker.cpp
 *
 *  Created on: 2017. okt. 21.
 *      Author: peti
 */

#include <layers/ClockProximityMarker.h>

namespace Layers {

/**
 * @param color marker color when visible
 * @param ledIndex position on the clock face
 * @param proximity check for clock features "this many LED's away"
 */
ClockProximityMarker::ClockProximityMarker(Color color, uint8_t ledIndex,
        uint8_t proximity) :
        ClockMarker(color, ledIndex), proximity(proximity) {
}

bool ClockProximityMarker::shouldBeVisible(Canvas& canvas) {
    // call super-class implementation first, and only go on if It would be visible
    bool super = ClockMarker::shouldBeVisible(canvas);
    if (super) {
        for (uint8_t i = 1; i <= proximity; i++) {
            if (canvas.isSet(ledIndex - i) || canvas.isSet(ledIndex + i)) {
                return true;
            }
        }
    }

    return false;
}

} /* namespace Layers */
