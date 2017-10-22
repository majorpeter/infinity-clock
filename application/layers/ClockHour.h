/*
 * LayerClock_Hour.h
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#ifndef LAYERCLOCK_HOUR_H_
#define LAYERCLOCK_HOUR_H_

#include "Layer.h"

namespace Layers {

class ClockHour: public Layer {
public:
    ClockHour(const Color color);
    virtual void render(Canvas& canvas, const Time& now, float brightness = 1.f);
private:
    Color color;
};

} /* namespace Layers */

#endif /* LAYERCLOCK_HOUR_H_ */
