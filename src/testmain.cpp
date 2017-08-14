/*
 * testmain.cpp
 *
 *  Created on: 2017. aug. 14.
 *      Author: peti
 */

#include "EventLoop.h"
#include "StateMachine_Initial.h"
#include "StateMachine_Clock.h"
#include "JsonCanvas.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return -2;
	}
	Canvas* canvas = new JsonCanvas(argv[1]);
	EventLoop* loop = new EventLoop(*canvas, new StateMachine_Clock(), new StateMachine_Initial());
	loop->run();
}