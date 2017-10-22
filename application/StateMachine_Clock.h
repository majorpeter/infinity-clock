/*
 * StateMachine_Clock.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef STATEMACHINE_CLOCK_H_
#define STATEMACHINE_CLOCK_H_

#include "Color.h"
#include "StateMachine.h"
#include "layers/ClockLayerCollection.h"

class Layer;

class StateMachine_Clock: public StateMachine {
public:
    StateMachine_Clock(Layers::ClockLayerCollection* layers);
    virtual void render(Canvas& canvas, const Time& now);
private:
    Layers::ClockLayerCollection* layers;
};

#endif /* STATEMACHINE_CLOCK_H_ */
