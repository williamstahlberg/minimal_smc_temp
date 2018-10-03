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

//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <IOKit/IOKitLib.h>
//#include "smc.h"
//#include <libkern/OSAtomic.h>
//
//#define OP_NONE               0
//#define OP_LIST               1
//#define OP_READ               2
//#define OP_READ_FAN           3
//#define OP_WRITE              4
//
//int c;
//extern char   *optarg;
//
//kern_return_t result;
//int           op = OP_NONE;
//UInt32Char_t  key = { 0 };
//SMCVal_t      val;

//int main(int argc, char *argv[])
//{
//	int c;
//	extern char   *optarg;
//	
//	kern_return_t result;
//	int           op = OP_NONE;
//	UInt32Char_t  key = { 0 };
//	SMCVal_t      val = {
//		.key = "F0Tg",
//		.dataSize = 2,
//		.dataType = "\xff\x7f",
//		.bytes = "\x55\xf0",
//	};
//	
//	while ((c = getopt(argc, argv, "fhk:lrw:v")) != -1)
//	{
//		switch(c)
//		{
//			case 'f':
//				op = OP_READ_FAN;
//				break;
//			case 'k':
//				strncpy(key, optarg, sizeof(key));   //fix for buffer overflow
//				key[sizeof(key) - 1] = '\0';
//				break;
//			case 'l':
//				op = OP_LIST;
//				break;
//			case 'r':
//				op = OP_READ;
//				break;
//			case 'v':
//				printf("%s\n", 0);
//				return 0;
//				break;
//			case 'w':
//				op = OP_WRITE;
//			{
//				int i;
//				char c[3];
//				for (i = 0; i < strlen(optarg); i++)
//				{
//					sprintf(c, "%c%c", optarg[i * 2], optarg[(i * 2) + 1]);
//					val.bytes[i] = (int) strtol(c, NULL, 16);
//				}
//				val.dataSize = i / 2;
//				if ((val.dataSize * 2) != strlen(optarg))
//				{
//					printf("Error: value is not valid\n");
//					return 1;
//				}
//			}
//				break;
//			case 'h':
//			case '?':
//				op = OP_NONE;
//				break;
//		}
//	}
//
//	if (op == OP_NONE)
//	{
//		usage(argv[0]);
//		return 1;
//	}
	
//	smc_init();

//	switch(op)
//	{
//		case OP_LIST:
//			result = SMCPrintAll();
//			if (result != kIOReturnSuccess)
//				printf("Error: SMCPrintAll() = %08x\n", result);
//			break;
//		case OP_READ:
//			if (strlen(key) > 0)
//			{
//				result = SMCReadKey(key, &val);
//				if (result != kIOReturnSuccess)
//					printf("Error: SMCReadKey() = %08x\n", result);
//				else
//					printVal(val);
//			}
//			else
//			{
//				printf("Error: specify a key to read\n");
//			}
//			break;
//		case OP_READ_FAN:
//			result = SMCPrintFans();
//			if (result != kIOReturnSuccess)
//				printf("Error: SMCPrintFans() = %08x\n", result);
//			break;
//		case OP_WRITE:
//			if (strlen(key) > 0)
//			{
//				sprintf(val.key, key);
//				result = SMCWriteKey(val);
//				if (result != kIOReturnSuccess)
//					printf("Error: SMCWriteKey() = %08x\n", result);
//			}
//			else
//			{
//				printf("Error: specify a key to write\n");
//			}
//			break;
//	}
	
//	smc_close();
//	return 0;
//}
