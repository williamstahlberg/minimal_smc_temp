#include "smc.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
	char *names[] = {
		"SMC BATTERY",
		"SMC BATTERY POSITION 2",
		"SMC BATTERY POSITION 3",
		"SMC CPU A DIODE",
		"SMC CPU A PROXIMITY",
		"SMC GPU 1 CHIP",
		"SMC GPU DIODE",
		"SMC LEFT PALM REST",
		"SMC MAIN HEAT SINK 2",
		"SMC MAIN HEAT SINK 3",
		"SMC MAIN LOGIC BOARD",
		"SMC PLATFORM CONTROLLER HUB",
		"Smart Battery A1309 (8)"
	};
	
	char *keys[] = {
		"TB0T", "TB1T", "TB2T", "TC1C", "TC0P", "TG0P", "TG0D", "Ts0P", "Th1H", "Th2H", "Tm0P", "TP0P", "TB0T"
	};
	
	size_t n = sizeof(keys)/sizeof(keys[0]);
	
	float *vals = getSmcValues(keys, n);
	
	for (int i = 0; i < n; i++) {
		printf("%s: %.0f\n", names[i], vals[i]);
	}
	
	//	allFans();

	return 0;
}
