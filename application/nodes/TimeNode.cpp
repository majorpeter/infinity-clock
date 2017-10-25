/*
 * TimeNode.cpp
 *
 *  Created on: 2017. okt. 25.
 *      Author: peti
 */

#include "TimeNode.h"
#include "Time.h"

#include <stdio.h>

MK_PROP_STRING_RO(TimeNode, Time, "RTC time");
MK_PROP_STRING_RO(TimeNode, UpTime, "Time since last startup");

PROP_ARRAY(props) = {
        PROP_ADDRESS(TimeNode, Time),
        PROP_ADDRESS(TimeNode, UpTime),
};

TimeNode::TimeNode(): Node("TIME") {
    NODE_SET_PROPS(props);
}

ProtocolResult_t TimeNode::getTime(char* dest) const {
    Time now = Time::now();
    sprintf(dest, "%lu:%02lu:%02lu",
            now.getSec() / 3600,
            (now.getSec() / 60) % 60,
            now.getSec() % 60);
    return ProtocolResult_Ok;
}

ProtocolResult_t TimeNode::getUpTime(char* dest) const {
    uint32_t ticks = Time::getTicksSinceStart();
    sprintf(dest, "%lu.%03lu s", ticks / 1000, ticks % 1000);
    return ProtocolResult_Ok;
}
