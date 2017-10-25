/*
 * Canvas.h
 *
 *  Created on: 2017. aug. 6.
 *      Author: peti
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include <stdint.h>
#include <ws2812-stm32/Color.h>

class Canvas {
public:
    Canvas(uint16_t ledCount);
    virtual ~Canvas();

    virtual void init() {}
    virtual void clear();
    virtual void fillColor(const Color color);
    virtual void add(int16_t index, const Color color);
    virtual void set(int16_t index, const Color color);
    virtual bool isSet(int16_t index);
    virtual void draw() = 0;
protected:
    const uint16_t ledCount;
    Color* leds;
private:
    inline int16_t fixIndexRange(int16_t index) {
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
