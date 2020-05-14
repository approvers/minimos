#ifndef __COMMON_H
#define __COMMON_H

#include "efi.h"

#define IN
#define OUT
#define OPTIONAL
#define CONST
#define EFIAPI

#define TRUE 1
#define FALSE 0
#define NULL 0

#define EFI_SUCCESS 0

#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

typedef void VOID;
typedef unsigned char BOOLEAN;
typedef signed char INT8;
typedef unsigned char UINT8;
typedef short int INT16;
typedef unsigned short int UINT16;
typedef int INT32;
typedef unsigned int UINT32;
typedef long int INT64;
typedef unsigned long int UINT64;
typedef long long int INT128;
typedef unsigned long long int UINT128;
typedef INT64 INTN;
typedef UINT64 UINTN;

typedef UINT16 CHAR16;

typedef UINTN EFI_STATUS;
typedef UINTN EFI_TPL;
typedef VOID* EFI_HANDLE;
typedef VOID* EFI_EVENT;

struct _EFI_TABLE_HEADER
{
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
};

typedef struct _EFI_TABLE_HEADER EFI_TABLE_HEADER;

#endif
