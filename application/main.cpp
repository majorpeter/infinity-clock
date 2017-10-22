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



    Qep* qep = Hardware::createRotaryEncoder();

    EventLoop* loop = new EventLoop(*canvas, *qep,
            new StateMachine_Clock(Color::red, Color::green, Color::blue, Color::white * 0.25f, Color::white * 0.15f),
            new StateMachine_Initial());
    loop->run();

    return 0;
}
