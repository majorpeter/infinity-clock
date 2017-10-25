/*
 * JsonCanvas.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "JsonCanvas.h"
#include <stdlib.h>

JsonCanvas::JsonCanvas(const char* fname): Canvas(60) {
    f = fopen(fname, "w");
    if (f == NULL) {
        exit(-1);
    }
    frame = 0;
    fprintf(f, "var json_data = {\n");
}

JsonCanvas::~JsonCanvas() {
    fclose(f);
}

void JsonCanvas::draw() {
    static const uint16_t maxFrames = 60 * 60;

    fprintf(f, "'%d': {\n", frame);
    for (uint16_t i = 0; i < ledCount; i++) {
        fprintf(f, "  '%hu': '#%02x%02x%02x'%c\n", i, leds[i].getRed(),
                leds[i].getGreen(), leds[i].getBlue(),
                (i == ledCount - 1) ? ' ' : ',');
    }
    fprintf(f, "}%c\n", (frame == maxFrames) ? ' ' : ',');

    frame++;
    if (frame == maxFrames) {
        fprintf(f, "};\n");
        exit(0);
    }
}
