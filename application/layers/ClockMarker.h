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

/**
 * A ClockMarker is visible if no other clock feature is shown in its position. Otherwise
 * it fades out and fades in when the 'other feature' disappears.
 */
class ClockMarker: public Layer {
public:
    ClockMarker(Color color, uint8_t ledIndex);
    virtual void render(Canvas& canvas, const Time& now, float brightness = 1.f);
protected:
    const uint8_t ledIndex;

    void hide(const Time& now);
    void show(const Time& now);
    virtual bool shouldBeVisible(Canvas& canvas);
private:
    enum class State {
        Hidden,
        Default,
        FadeOut,
        FadeIn,
    };

    Color color;
    State state;
    uint32_t animationStartMs;
};

} /* namespace Layers */

#endif /* LAYERS_CLOCKMARKER_H_ */
