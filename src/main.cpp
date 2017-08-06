#include "Hardware.h"
#include "Canvas.h"
#include "Color.h"
#include "Time.h"
#include "diag/Trace.h"

int main() {
	Hardware::RCC_Init();
	Hardware::GPIO_Remap();
	Hardware::SysTickInit();
	Hardware::RTC_Init();
	Hardware::IRQ_Init();

	Canvas canvas(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin, Hardware::LedOffset, Hardware::LedsReversed);
	canvas.init();

	while(1) {
		uint8_t sec = Time::now().getSec() % 60;
		canvas.fillColor(Color(0,0,0));
		canvas.set(sec, Color(0, 0, 255));
		canvas.draw();
	}

	return 0;
}
