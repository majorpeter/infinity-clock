/*
 * testmain.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "EventLoop.h"
#include "StateMachine_Clock.h"
#include "JsonCanvas.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return -2;
    }
    Canvas* canvas = new JsonCanvas(argv[1]);
    EventLoop* loop = new EventLoop(*canvas,
            new StateMachine_Clock(Color::red, Color::green, Color::blue, Color::white * 0.85f),
            NULL);

    Time::setNow(Time(3600 + 59 * 60 + 56, 0));
    loop->run();
}
