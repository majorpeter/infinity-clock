/*
 * Canvas.cpp
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#include "Canvas.h"

Canvas::Canvas(GPIO_TypeDef const* dataOutGpioPort, uint16_t dataOutGpioPin,
		uint16_t ledIndexOffset, bool reverse) :
		LedStripController(dataOutGpioPort, dataOutGpioPin, ledIndexOffset, reverse) {
}

void Canvas::init() {
	LedStripController::init();
}

void Canvas::fillColor(Color color) {
	for (uint16_t i = 0; i < ledCount; i++) {
		leds[i] = color;
	}
}

void Canvas::set(uint16_t index, const Color color) {
	leds[index] = color;
}

void Canvas::draw() {
	LedStripController::writeLeds(leds, ledCount);
}
