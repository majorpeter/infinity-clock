/*
 * Canvas.h
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include "Color.h"

class Canvas {
public:
	static const uint16_t ledCount = 60;

	Canvas();
	virtual ~Canvas() {}

	virtual void init() {}
	virtual void clear();
	virtual void fillColor(const Color color);
	virtual void set(uint16_t index, const Color color);
	virtual void draw() = 0;
protected:
	Color leds[ledCount];
};

#endif /* CANVAS_H_ */
