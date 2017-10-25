/*
 * HardwareCanvas.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "HardwareCanvas.h"

HardwareCanvas::HardwareCanvas(GPIO_TypeDef * const dataOutGpioPort,
        uint16_t dataOutGpioPin, uint16_t maxLedCount, uint16_t ledIndexOffset, bool reverse) :
        Canvas(maxLedCount),
        ledStrip(dataOutGpioPort, dataOutGpioPin, maxLedCount, ledIndexOffset, reverse) {
}

void HardwareCanvas::init() {
    ledStrip.init();
}

void HardwareCanvas::draw() {
    ledStrip.writeLeds(leds, ledCount);
}
