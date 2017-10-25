/*
 * LedStripNode.h
 *
 *  Created on: 2017. okt. 25.
 *      Author: peti
 */

#ifndef LEDSTRIPNODE_H_
#define LEDSTRIPNODE_H_

#include <mprotocol-nodes/Node.h>

class Canvas;

class CanvasNode: public Node {
public:
    DECLARE_PROP_BINARY_RW(ColorHex);
    DECLARE_PROP_STRING_RW(ColorRgb);
    DECLARE_PROP_METHOD(clear);
    DECLARE_PROP_METHOD(setRed);
    DECLARE_PROP_METHOD(setWhite);

    CanvasNode(Canvas* controller);
    virtual ~CanvasNode() {}
private:
    Canvas* canvas;
    uint8_t rgbBytes[3];
};

#endif /* LEDSTRIPNODE_H_ */
