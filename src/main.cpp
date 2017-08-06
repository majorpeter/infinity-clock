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

	LedStripController ledStrip(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin);
	ledStrip.init();

	Color red(255, 0, 0);
	while(1) {
		ledStrip.writeLeds(&red, 1);
	}

	return 0;
}
