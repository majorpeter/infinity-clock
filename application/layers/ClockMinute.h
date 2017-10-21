/*
 * Layer_ClockMinute.h
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#ifndef LAYER_CLOCKMINUTE_H_
#define LAYER_CLOCKMINUTE_H_

#include "Layer.h"

namespace Layers {

class ClockMinute: public Layer {
public:
    ClockMinute(const Color color);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Color color;
};

} /* namespace Layers */

#endif /* LAYER_CLOCKMINUTE_H_ */
