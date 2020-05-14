#ifndef __CONFIGURATION_TABLE_H
#define __CONFIGURATION_TABLE_H

#include "efi.h"

struct _EFI_CONFIGURATION_TABLE
{
    EFI_GUID VendorGuid;
    VOID* VendorTable;
};

typedef struct _EFI_CONFIGURATION_TABLE EFI_CONFIGURATION_TABLE;

#endif
