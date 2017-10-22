/*
 * Layer_ClockSecond.h
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#ifndef LAYER_CLOCKSECOND_H_
#define LAYER_CLOCKSECOND_H_

#include "Layer.h"

namespace Layers {

class ClockSecond: public Layer {
public:
    ClockSecond(const Color color);
    virtual void render(Canvas& canvas, const Time& now, float brightness = 1.f);
private:
    Color color;
};

} /* namespace Layers */

#endif /* LAYER_CLOCKSECOND_H_ */
