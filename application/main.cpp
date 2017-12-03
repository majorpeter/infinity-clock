#include "Hardware.h"
#include "HardwareCanvas.h"
#include "Time.h"
#include "diag/Trace.h"

#include "StateMachine_Initial.h"
#include "StateMachine_Clock.h"
#include "StateMachine_ClockSetup.h"
#include "layers/ClockHour.h"
#include "layers/ClockMinute.h"
#include "layers/ClockSecond.h"
#include "layers/ClockMarker.h"
#include "layers/ClockProximityMarker.h"
#include "EventLoop.h"

#include "EspLink.h"
#include <ws2812-stm32/LedStripController.h>
#include <mprotocol-server/ProtocolParser.h>
#include <mprotocol-nodes/RootNode.h>

#include "nodes/TimeNode.h"
#include "nodes/CanvasNode.h"

int main() {
    Hardware::RCC_Init();
    Hardware::GPIO_Remap();
    Hardware::SysTickInit();
    Hardware::RTC_Init();
    Hardware::IRQ_Init();

    //TODO maybe a nicer way to wait for first SysTick?
    while (Time::now().getMsec() == 0);

    Canvas* canvas = new HardwareCanvas(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin, 60, Hardware::LedOffset, Hardware::LedsReversed);
    canvas->init();

    Layers::ClockLayerCollection layers;
    layers.hour = new Layers::ClockHour(Color::red);
    layers.minute = new Layers::ClockMinute(Color::green);
    layers.second = new Layers::ClockSecond(Color::blue);

    // The four cardinal directions or cardinal points are the directions north, east, south, and west
    static const Color colorCardinalDirections = Color::white * 0.15f;
    layers.markers[0] = new Layers::ClockMarker(colorCardinalDirections, 0);
    layers.markers[1] = new Layers::ClockMarker(colorCardinalDirections, 15);
    layers.markers[2] = new Layers::ClockMarker(colorCardinalDirections, 30);
    layers.markers[3] = new Layers::ClockMarker(colorCardinalDirections, 45);

    static const Color colorProximityMarkers = Color::white * 0.08f;
    static const uint8_t proximity = 3;
    layers.markers[4] = new Layers::ClockProximityMarker(colorProximityMarkers, 5, proximity);
    layers.markers[5] = new Layers::ClockProximityMarker(colorProximityMarkers, 10, proximity);
    layers.markers[6] = new Layers::ClockProximityMarker(colorProximityMarkers, 20, proximity);
    layers.markers[7] = new Layers::ClockProximityMarker(colorProximityMarkers, 25, proximity);
    layers.markers[8] = new Layers::ClockProximityMarker(colorProximityMarkers, 35, proximity);
    layers.markers[9] = new Layers::ClockProximityMarker(colorProximityMarkers, 40, proximity);
    layers.markers[10] = new Layers::ClockProximityMarker(colorProximityMarkers, 50, proximity);
    layers.markers[11] = new Layers::ClockProximityMarker(colorProximityMarkers, 55, proximity);
    new StateMachine_Clock(&layers);
    new StateMachine_ClockSetup(&layers);

    RootNode::getInstance()->addChild(new TimeNode());
    RootNode::getInstance()->addChild(new CanvasNode(canvas));

    EspLink* serialInterface = new EspLink(Hardware::EspResetPort,
            Hardware::EspResetPin, Hardware::EspChPdPort, Hardware::EspChPdPin);
    ProtocolParser* protocol = new ProtocolParser(serialInterface);
    serialInterface->listen();

    Qep* qep = Hardware::createRotaryEncoder();
    FunctionButton* button = Hardware::createFunctionButton();
    EventLoop* loop = new EventLoop(*canvas, *qep, *button, protocol,
            new StateMachine_Initial());
    loop->run();

    return 0;
}
