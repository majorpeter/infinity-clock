/*
 * Canvas.cpp
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#include "Canvas.h"

Canvas::Canvas() {
}

void Canvas::clear() {
	this->fillColor(Color::black);
}

void Canvas::fillColor(const Color color) {
	for (uint16_t i = 0; i < ledCount; i++) {
		leds[i] = color;
	}
}

void Canvas::add(int16_t index, const Color color) {
	leds[fixIndexRange(index)] += color;
}

void Canvas::set(int16_t index, const Color color) {
	leds[fixIndexRange(index)] = color;
}
