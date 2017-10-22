/*
 * FunctionButton.h
 *
 *  Created on: 2017. okt. 22.
 *      Author: peti
 */

#ifndef FUNCTIONBUTTON_H_
#define FUNCTIONBUTTON_H_

#include <stm32f10x.h>

class FunctionButton {
public:
    enum class Event {
        None,
        ShortPress,
        LongPress
    };

    FunctionButton(GPIO_TypeDef * const port, uint16_t pin);
    ~FunctionButton() {}

    void init();
    void update();

    inline Event getEvent() const {
        return event;
    }
private:
    GPIO_TypeDef * const port;
    uint16_t pin;

    Event event;
    uint8_t pinValue;
    uint32_t pressStartMs;
};

#endif /* FUNCTIONBUTTON_H_ */
