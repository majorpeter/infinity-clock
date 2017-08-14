#include "Hardware.h"
#include "HardwareCanvas.h"
#include "Color.h"
#include "Time.h"
#include "diag/Trace.h"

int main() {
	Hardware::RCC_Init();
	Hardware::GPIO_Remap();
	Hardware::SysTickInit();
	Hardware::RTC_Init();
	Hardware::IRQ_Init();

	Canvas* canvas = new HardwareCanvas(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin, Hardware::LedOffset, Hardware::LedsReversed);
	canvas->init();

	while(1) {
		uint8_t min = (Time::now().getSec() / 60) % 60;
		uint8_t sec = Time::now().getSec() % 60;
		canvas->fillColor(Color(0,0,0));
		canvas->set(min, Color(0, 255, 0));
		canvas->set(sec, Color(0, 0, 255));
		canvas->draw();
	}

	return 0;
}
