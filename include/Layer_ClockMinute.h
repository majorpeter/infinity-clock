/*
 * Layer_ClockMinute.h
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#ifndef LAYER_CLOCKMINUTE_H_
#define LAYER_CLOCKMINUTE_H_

#include "Layer.h"

class Layer_ClockMinute: public Layer {
public:
    Layer_ClockMinute(const Color color);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Color color;
};

#endif /* LAYER_CLOCKMINUTE_H_ */
