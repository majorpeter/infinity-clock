/*
 * LayerClock_Hour.h
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#ifndef LAYERCLOCK_HOUR_H_
#define LAYERCLOCK_HOUR_H_

#include "Layer.h"

class Layer_ClockHour: public Layer {
public:
    Layer_ClockHour(const Color color);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Color color;
};

#endif /* LAYERCLOCK_HOUR_H_ */
