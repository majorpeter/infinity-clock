/*
 * HardwareCanvas.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef HARDWARECANVAS_H_
#define HARDWARECANVAS_H_

#include "Canvas.h"
#include "ws2812-stm32/LedStripController.h"

class HardwareCanvas: public Canvas {
public:
    HardwareCanvas(GPIO_TypeDef const* dataOutGpioPort, uint16_t dataOutGpioPin, uint16_t ledIndexOffset, bool reverse);
    virtual ~HardwareCanvas() {}

    virtual void init();
    virtual void draw();
private:
    LedStripController ledStrip;
};

#endif /* HARDWARECANVAS_H_ */
