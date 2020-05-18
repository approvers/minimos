#ifndef __RUNTIME_SERVICES_H
#define __RUNTIME_SERVICES_H

#include "efi.h"

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

enum _EFI_RESET_TYPE
{
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific,
};

union _EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS
{
    EFI_PHYSICAL_ADDRESS DataBlock;
    EFI_PHYSICAL_ADDRESS ContinuationPointer;
};

typedef union _EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS;

struct _EFI_CAPSULE_BLOCK_DESCRIPTOR
{
    UINT64 Length;
    EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS Union;
};

struct _EFI_CAPSULE_HEADER
{
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
};

typedef enum _EFI_RESET_TYPE EFI_RESET_TYPE;
typedef struct _EFI_CAPSULE_BLOCK_DESCRIPTOR EFI_CAPSULE_BLOCK_DESCRIPTOR;
typedef struct _EFI_CAPSULE_HEADER EFI_CAPSULE_HEADER;

typedef EFI_STATUS (*EFI_GET_TIME)(EFI_TIME* Time, EFI_TIME_CAPABILITIES* Capabilities);
typedef EFI_STATUS (*EFI_SET_TIME)(EFI_TIME* Time);
typedef EFI_STATUS (*EFI_GET_WAKEUP_TIME)(BOOLEAN* Enabled, BOOLEAN* Pending, EFI_TIME* Time);
typedef EFI_STATUS (*EFI_SET_WAKEUP_TIME)(BOOLEAN Enable, EFI_TIME* Time);
typedef EFI_STATUS (*EFI_SET_VIRTUAL_ADDRESS_MAP)(UINTN MemoryMapSize, UINTN DescriptorSize, UINT32 DescriptorVersion, EFI_MEMORY_DESCRIPTOR* VirtualMap);
typedef EFI_STATUS (*EFI_CONVERT_POINTER)(UINTN DebugDisposition, VOID** Address);
typedef EFI_STATUS (*EFI_GET_VARIABLE)(CHAR16* VariableName, EFI_GUID* VendorGuid, UINT32* Attributes, UINTN* DataSize, VOID* Data);
typedef EFI_STATUS (*EFI_GET_NEXT_VARIABLE_NAME)(UINTN* VariableNameSize, CHAR16* VariableName, EFI_GUID* VendorGuid);
typedef EFI_STATUS (*EFI_SET_VARIABLE)(CHAR16* VariableName, EFI_GUID* VendorGuid, UINT32 Attributes, UINTN DataSize, VOID* Data);
typedef EFI_STATUS (*EFI_GET_NEXT_HIGH_MONO_COUNT)(UINT32* HighCount);
typedef EFI_STATUS (*EFI_RESET_SYSTEM)(EFI_RESET_TYPE ResetType, EFI_STATUS ResetStatus, UINTN DataSize, VOID* ResetData);
typedef EFI_STATUS (*EFI_UPDATE_CAPSULE)(EFI_CAPSULE_HEADER** CapsuleHeaderArray, UINTN CapsuleCount, EFI_PHYSICAL_ADDRESS ScatterGatherList);
typedef EFI_STATUS (*EFI_QUERY_CAPSULE_CAPABILITIES)(EFI_CAPSULE_HEADER** CapsuleHeaderArray, UINTN CapsuleCount, UINT64* MaximumCapsuleSize, EFI_RESET_TYPE* ResetType);
typedef EFI_STATUS (*EFI_QUERY_VARIABLE_INFO)(UINT32 Attributes, UINT64* MaximumVariableStorageSize, UINT64* RemainingVariableStorageSize, UINT64* MaximumVariableSize);

struct _EFI_RUNTIME_SERVICES
{
    EFI_TABLE_HEADER Hdr;
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;
    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;
    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
};

typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

#endif
