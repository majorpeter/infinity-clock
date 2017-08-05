#include "Hardware.h"
#include "diag/Trace.h"

int main(int argc, char* argv[]) {
	Hardware::RCC_Init();
	Hardware::GPIO_Remap();
	Hardware::SysTickInit();
	Hardware::RTC_Init();

	return 0;
}
