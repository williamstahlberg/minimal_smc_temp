#ifndef smc_h
#define smc_h

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <IOKit/IOKitLib.h>
#include <libkern/OSAtomic.h>

#define SMC_CMD_READ_KEYINFO  9
#define KERNEL_INDEX_SMC      2
#define SMC_CMD_READ_BYTES    5

#define SMC_CMD_WRITE_BYTES   6

typedef char              UInt32Char_t[5];
typedef unsigned char     SMCBytes_t[32];

typedef struct {
	UInt32Char_t            key;
	UInt32                  dataSize;
	UInt32Char_t            dataType;
	SMCBytes_t              bytes;
} SMCVal_t;

typedef struct {
	char                  major;
	char                  minor;
	char                  build;
	char                  reserved[1];
	UInt16                release;
} SMCKeyData_vers_t;

typedef struct {
	UInt16                version;
	UInt16                length;
	UInt32                cpuPLimit;
	UInt32                gpuPLimit;
	UInt32                memPLimit;
} SMCKeyData_pLimitData_t;

typedef struct {
	UInt32                dataSize;
	UInt32                dataType;
	char                  dataAttributes;
} SMCKeyData_keyInfo_t;

typedef struct {
	UInt32                  key;
	SMCKeyData_vers_t       vers;
	SMCKeyData_pLimitData_t pLimitData;
	SMCKeyData_keyInfo_t    keyInfo;
	char                    result;
	char                    status;
	char                    data8;
	UInt32                  data32;
	SMCBytes_t              bytes;
} SMCKeyData_t;

float getSmcValue(char *key);
float *getSmcValues(char *keys[], size_t n);

void allFans();

#endif /* smc_h */
