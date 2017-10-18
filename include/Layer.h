/*
 * Layer.h
 *
 *  Created on: 2017. okt. 18.
 *      Author: peti
 */

#ifndef LAYER_H_
#define LAYER_H_

#include "Canvas.h"
#include "Time.h"

class Layer {
public:
    virtual ~Layer() {}
    virtual void render(Canvas& canvas, const Time& now) = 0;
};

#endif /* LAYER_H_ */
