/*
 * JsonCanvas.h
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#ifndef JSONCANVAS_H_
#define JSONCANVAS_H_

#include "Canvas.h"
#include <stdio.h>

class JsonCanvas: public Canvas {
public:
	JsonCanvas(const char* fname);
	virtual ~JsonCanvas();
	virtual void draw();
private:
	FILE* f;
	uint16_t frame;
};

#endif /* JSONCANVAS_H_ */
