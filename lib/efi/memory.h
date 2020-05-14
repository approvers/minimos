#ifndef __MEMORY_H
#define __MEMORY_H

#include "efi.h"

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

struct _EFI_MEMORY_DESCRIPTOR
{
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
};

typedef struct _EFI_MEMORY_DESCRIPTOR EFI_MEMORY_DESCRIPTOR;

#endif
