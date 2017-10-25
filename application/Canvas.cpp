/*
 * Canvas.cpp
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#include "Canvas.h"
#include <ws2812-stm32/Color.h>

Canvas::Canvas(uint16_t ledCount): ledCount(ledCount) {
    leds = new Color[ledCount];
}

Canvas::~Canvas() {
    delete[] leds;
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

bool Canvas::isSet(int16_t index) {
    return !(leds[fixIndexRange(index)] == Color::black);
}
