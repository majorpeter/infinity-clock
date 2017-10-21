/*
 * ClockProximityMarker.h
 *
 *  Created on: 2017. okt. 21.
 *      Author: peti
 */

#ifndef LAYERS_CLOCKPROXIMITYMARKER_H_
#define LAYERS_CLOCKPROXIMITYMARKER_H_

#include "ClockMarker.h"

namespace Layers {

/**
 * A ClockProximityMarker is only visible when something is near it, and disappears when
 * another clock feature is present at its position (just like a regular ClockMarker).
 */
class ClockProximityMarker: public ClockMarker {
public:
    ClockProximityMarker(Color color, uint8_t ledIndex, uint8_t proximity);
protected:
    virtual bool shouldBeVisible(Canvas& canvas);
private:
    uint8_t proximity;
};

} /* namespace Layers */

#endif /* LAYERS_CLOCKPROXIMITYMARKER_H_ */
