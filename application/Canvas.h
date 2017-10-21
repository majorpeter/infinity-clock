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
    virtual void add(int16_t index, const Color color);
    virtual void set(int16_t index, const Color color);
    virtual bool isSet(int16_t index);
    virtual void draw() = 0;
protected:
    Color leds[ledCount];
private:
    static inline int16_t fixIndexRange(int16_t index) {
        if (index < 0) {
            return index + ledCount;
        }
        if (index >= ledCount) {
            return index - ledCount;
        }
        return index;
    }
};

#endif /* CANVAS_H_ */
