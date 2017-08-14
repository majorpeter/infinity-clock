/*
 * HardwareCanvas.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "HardwareCanvas.h"

HardwareCanvas::HardwareCanvas(GPIO_TypeDef const* dataOutGpioPort, uint16_t dataOutGpioPin,
		uint16_t ledIndexOffset, bool reverse) :
		LedStripController(dataOutGpioPort, dataOutGpioPin, ledIndexOffset, reverse) {
}

void HardwareCanvas::draw() {
	LedStripController::writeLeds(leds, ledCount);
}
