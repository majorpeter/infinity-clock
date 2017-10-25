/*
 * LedStripNode.cpp
 *
 *  Created on: 2017. okt. 25.
 *      Author: peti
 */

#include "CanvasNode.h"
#include "Canvas.h"

MK_PROP_METHOD(CanvasNode, clear, "Clears LED's");
MK_PROP_METHOD(CanvasNode, setRed, "Sets all LED's to red");
MK_PROP_METHOD(CanvasNode, setWhite, "Sets all LED's to white");

PROP_ARRAY(props) = {
        PROP_ADDRESS(CanvasNode, clear),
        PROP_ADDRESS(CanvasNode, setRed),
        PROP_ADDRESS(CanvasNode, setWhite),
};

CanvasNode::CanvasNode(Canvas* canvas): Node("CANVAS"), canvas(canvas) {
    NODE_SET_PROPS(props);
}

ProtocolResult_t CanvasNode::invokeclear(const char*) {
    canvas->clear();
    canvas->draw();
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::invokesetRed(const char*) {
    canvas->fillColor(Color::red);
    canvas->draw();
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::invokesetWhite(const char*) {
    canvas->fillColor(Color::white);
    canvas->draw();
    return ProtocolResult_Ok;
}
