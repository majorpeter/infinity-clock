/*
 * Layer_ClockSecond.h
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#ifndef LAYER_CLOCKSECOND_H_
#define LAYER_CLOCKSECOND_H_

#include "Layer.h"

class Layer_ClockSecond: public Layer {
public:
    Layer_ClockSecond(const Color color);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Color color;
};

#endif /* LAYER_CLOCKSECOND_H_ */
