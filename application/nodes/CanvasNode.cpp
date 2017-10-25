/*
 * LedStripNode.cpp
 *
 *  Created on: 2017. okt. 25.
 *      Author: peti
 */

#include "CanvasNode.h"
#include "Canvas.h"
#include <ws2812-stm32/Color.h>
#include <stdio.h>

MK_PROP_BINARY_RW(CanvasNode, ColorHex, "Current color in hexadecimal digits");
MK_PROP_STRING_RW(CanvasNode, ColorRgb, "Current color as RGB decimal values");
MK_PROP_METHOD(CanvasNode, clear, "Clears LED's");
MK_PROP_METHOD(CanvasNode, setRed, "Sets all LED's to red");
MK_PROP_METHOD(CanvasNode, setWhite, "Sets all LED's to white");

PROP_ARRAY(props) = {
        PROP_ADDRESS(CanvasNode, ColorHex),
        PROP_ADDRESS(CanvasNode, ColorRgb),
        PROP_ADDRESS(CanvasNode, clear),
        PROP_ADDRESS(CanvasNode, setRed),
        PROP_ADDRESS(CanvasNode, setWhite),
};

CanvasNode::CanvasNode(Canvas* canvas): Node("CANVAS"), canvas(canvas) {
    NODE_SET_PROPS(props);

    rgbBytes[0] = 0;
    rgbBytes[1] = 0;
    rgbBytes[2] = 0;
}

ProtocolResult_t CanvasNode::getColorHex(const void** dest, uint16_t* length) const {
    *dest = rgbBytes;
    *length = sizeof(rgbBytes);
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::setColorHex(const void* value, uint16_t length) {
    if (length != sizeof(rgbBytes)) {
        return ProtocolResult_InvalidValue;
    }
    const uint8_t* bytes = static_cast<const uint8_t*>(value);
    rgbBytes[0] = bytes[0];
    rgbBytes[1] = bytes[1];
    rgbBytes[2] = bytes[2];

    Color c(rgbBytes[0], rgbBytes[1], rgbBytes[2]);
    canvas->fillColor(c);
    canvas->draw();

    invalidateProperty(&prop_ColorRgb);
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::getColorRgb(char* dest) const {
    sprintf(dest, "%d,%d,%d", (int) rgbBytes[0], (int) rgbBytes[1], (int) rgbBytes[2]);
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::setColorRgb(const char* value) {
    int r, g, b;
    if (sscanf(value, "%d,%d,%d", &r, &g, &b) != 3) {
        return ProtocolResult_InvalidValue;
    }
    rgbBytes[0] = r;
    rgbBytes[1] = g;
    rgbBytes[2] = b;

    Color c(r, g, b);
    canvas->fillColor(c);
    canvas->draw();

    invalidateProperty(&prop_ColorHex);
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::invokeclear(const char*) {
    uint8_t bytes[] = {0, 0, 0};
    setColorHex(bytes, sizeof(bytes));
    invalidateProperty(&prop_ColorHex);
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::invokesetRed(const char*) {
    uint8_t bytes[] = {255, 0, 0};
    setColorHex(bytes, sizeof(bytes));
    invalidateProperty(&prop_ColorHex);
    return ProtocolResult_Ok;
}

ProtocolResult_t CanvasNode::invokesetWhite(const char*) {
    uint8_t bytes[] = {255, 255, 255};
    setColorHex(bytes, sizeof(bytes));
    invalidateProperty(&prop_ColorHex);
    return ProtocolResult_Ok;
}
