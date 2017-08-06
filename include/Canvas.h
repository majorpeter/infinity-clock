/*
 * Canvas.h
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include "LedStripController.h"
#include "Color.h"

class Canvas: private LedStripController {
public:
	static const uint16_t ledCount = 60;

	Canvas(GPIO_TypeDef const* dataOutGpioPort, uint16_t dataOutGpioPin, uint16_t ledIndexOffset, bool reverse);
	~Canvas() {}

	void init();
	void fillColor(const Color color);
	void set(uint16_t index, const Color color);
	void draw();
private:
	Color leds[ledCount];
};

#endif /* CANVAS_H_ */
