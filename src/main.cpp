#include "Hardware.h"
#include "Canvas.h"
#include "Color.h"
#include "diag/Trace.h"

int main() {
	Hardware::RCC_Init();
	Hardware::GPIO_Remap();
	Hardware::SysTickInit();
	Hardware::RTC_Init();
	Hardware::IRQ_Init();

	Canvas canvas(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin, Hardware::LedOffset, Hardware::LedsReversed);
	canvas.init();

	canvas.fillColor(Color(0, 255, 0));
	while(1) {
		canvas.draw();
	}

	return 0;
}
