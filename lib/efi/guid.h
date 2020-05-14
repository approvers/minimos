#ifndef __GUID_H
#define __GUID_H

#include "efi.h"

struct _EFI_GUID
{
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
};

typedef struct _EFI_GUID EFI_GUID;

#endif
