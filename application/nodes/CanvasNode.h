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
    DECLARE_PROP_METHOD(clear);
    DECLARE_PROP_METHOD(setRed);
    DECLARE_PROP_METHOD(setWhite);

    CanvasNode(Canvas* controller);
    virtual ~CanvasNode() {}
private:
    Canvas* canvas;
};

#endif /* LEDSTRIPNODE_H_ */
