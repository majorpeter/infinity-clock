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
    static StateMachine_Clock* getInstance();

    virtual StateMachine* update(const Qep& qep, const FunctionButton& button, const Time& now);
    virtual void render(Canvas& canvas, const Time& now);
private:
    static StateMachine_Clock* instance;
    Layers::ClockLayerCollection* layers;
    float brightness;
};

#endif /* STATEMACHINE_CLOCK_H_ */
