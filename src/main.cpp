#include "Hardware.h"
#include "HardwareCanvas.h"
#include "Time.h"
#include "diag/Trace.h"

#include "StateMachine_Initial.h"
#include "StateMachine_Clock.h"
#include "EventLoop.h"

int main() {
	Hardware::RCC_Init();
	Hardware::GPIO_Remap();
	Hardware::SysTickInit();
	Hardware::RTC_Init();
	Hardware::IRQ_Init();

	//TODO maybe a nicer way to wait for first SysTick?
	while (Time::now().getMsec() == 0);

	Canvas* canvas = new HardwareCanvas(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin, Hardware::LedOffset, Hardware::LedsReversed);
	canvas->init();

	EventLoop* loop = new EventLoop(*canvas, new StateMachine_Clock(), new StateMachine_Initial());
	loop->run();

	return 0;
}
