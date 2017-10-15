/*
 * Color.cpp
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#include "Color.h"

const Color Color::black(0, 0, 0);
const Color Color::red(maxChannelValue, 0, 0);
const Color Color::green(0, maxChannelValue, 0);
const Color Color::blue(0, 0, maxChannelValue);

Color::Color() {
	color.value = 0;
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue) {
	color.components.red = red;
	color.components.green = green;
	color.components.blue = blue;
}

Color::Color(const Color& c) {
	this->color.value = c.color.value;
}

/**
 * add other color saturated to 'maxChannelValue'
 * @param c other color
 * @return this color after add
 */
Color& Color::operator+=(const Color& c) {
	uint16_t channelValue = getRed() + c.getRed();
	color.components.red = (channelValue < maxChannelValue) ? channelValue : maxChannelValue;
	channelValue = getGreen() + c.getGreen();
	color.components.green = (channelValue < maxChannelValue) ? channelValue : maxChannelValue;
	channelValue = getBlue() + c.getBlue();
	color.components.blue = (channelValue < maxChannelValue) ? channelValue : maxChannelValue;

	return *this;
}
