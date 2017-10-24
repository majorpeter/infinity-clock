/*
 * StateMachine_Clock.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef STATEMACHINE_CLOCKSETUP_H_
#define STATEMACHINE_CLOCKSETUP_H_

#include "StateMachine.h"
#include "Time.h"
#include "layers/ClockLayerCollection.h"
#include "ws2812-stm32/Color.h"

class Layer;

class StateMachine_ClockSetup: public StateMachine {
public:
    StateMachine_ClockSetup(Layers::ClockLayerCollection* layers);
    static StateMachine_ClockSetup* getInstance();

    virtual void onEnter();
    virtual StateMachine* update(const Qep& qep, const FunctionButton& button, const Time& now);
    virtual void render(Canvas& canvas, const Time& now);
private:
    enum class State {HourSetting, MinuteSetting, SecondSetting};

    Time timeToSet;
    int32_t qepAbsValue;
    static StateMachine_ClockSetup* instance;
    Layers::ClockLayerCollection* layers;
    State state;
};

#endif /* STATEMACHINE_CLOCKSETUP_H_ */
