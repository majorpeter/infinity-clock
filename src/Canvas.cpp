/*
 * Canvas.cpp
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#include "Canvas.h"

Canvas::Canvas() {
}

void Canvas::fillColor(Color color) {
	for (uint16_t i = 0; i < ledCount; i++) {
		leds[i] = color;
	}
}

void Canvas::set(uint16_t index, const Color color) {
	leds[index] = color;
}
