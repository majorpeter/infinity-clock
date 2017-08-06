#include "Hardware.h"
#include "LedStripController.h"
#include "diag/Trace.h"

int main() {
	Hardware::RCC_Init();
	Hardware::GPIO_Remap();
	Hardware::SysTickInit();
	Hardware::RTC_Init();
	Hardware::IRQ_Init();

	LedStripController ledStrip(Hardware::LedStripDataOutPort, Hardware::LedStripDataOutPin);
	ledStrip.init();

	while(1) {
		ledStrip.writeLeds();
	}

	return 0;
}
