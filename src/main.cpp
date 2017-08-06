#include "Hardware.h"
#include "LedStripController.h"
#include "Color.h"
#include "diag/Trace.h"

int main() {
	Hardware::RCC_Init();
	Hardware::GPIO_Remap();
	Hardware::SysTickInit();
	Hardware::RTC_Init();
	Hardware::IRQ_Init();

	LedStripController ledStrip(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin, 29, true);
	ledStrip.init();

	Color colors[] = {
			Color(255, 0, 0),
			Color(55, 0, 0),
			Color(0, 200, 0),
			Color(2, 0, 222),
			Color(155, 0, 100),
			Color(25, 24, 24),
			Color(0, 0, 0),
			Color(0, 220, 220),
	};
	while(1) {
		ledStrip.writeLeds(colors, sizeof(colors) / sizeof(colors[0]));
	}

	return 0;
}
