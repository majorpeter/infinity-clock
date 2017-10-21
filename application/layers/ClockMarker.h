/*
 * ClockMarker.h
 *
 *  Created on: 2017. okt. 21.
 *      Author: peti
 */

#ifndef LAYERS_CLOCKMARKER_H_
#define LAYERS_CLOCKMARKER_H_

#include "Layer.h"

namespace Layers {

class ClockMarker: public Layer {
public:
    ClockMarker(Color color, uint8_t ledIndex);
    virtual void render(Canvas& canvas, const Time& now);
private:
    enum class State {
        Hidden,
        Default,
        FadeOut,
        FadeIn,
    };

    Color color;
    uint8_t ledIndex;

    State state;
    uint32_t animationStartMs;

    bool shouldBeVisible(Canvas& canvas);
};

} /* namespace Layers */

#endif /* LAYERS_CLOCKMARKER_H_ */
