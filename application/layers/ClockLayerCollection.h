/*
 * ClockLayerCollection.h
 *
 *  Created on: 2017. okt. 22.
 *      Author: peti
 */

#ifndef LAYERS_CLOCKLAYERCOLLECTION_H_
#define LAYERS_CLOCKLAYERCOLLECTION_H_

namespace Layers {

class ClockHour;
class ClockMinute;
class ClockSecond;
class ClockMarker;

typedef struct {
    ClockHour* hour;
    ClockMinute* minute;
    ClockSecond* second;
    ClockMarker* markers[60 / 5];
} ClockLayerCollection;

}; /* namespace Layers */

#endif /* LAYERS_CLOCKLAYERCOLLECTION_H_ */
