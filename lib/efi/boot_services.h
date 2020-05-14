#ifndef __BOOT_SERVICES_H
#define __BOOT_SERVICES_H

#include "efi.h"

enum _EFI_TIMER_DELAY
{
    TimerCancel,
    TimerPeriodic,
    TimerRelative,
};

enum _EFI_ALLOCATE_TYPE
{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType,
};

enum _EFI_INTERFACE_TYPE
{
    EFI_NATIVE_INTERFACE,
};

enum _EFI_LOCATE_SEARCH_TYPE
{
    AllHandles,
    ByRegisterNotify,
    ByProtocol,
};

struct _EFI_OPEN_PROTOCOL_INFORMATION_ENTRY
{
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
};

typedef enum _EFI_TIMER_DELAY EFI_TIMER_DELAY;
typedef enum _EFI_ALLOCATE_TYPE EFI_ALLOCATE_TYPE;
typedef enum _EFI_INTERFACE_TYPE EFI_INTERFACE_TYPE;
typedef enum _EFI_LOCATE_SEARCH_TYPE EFI_LOCATE_SEARCH_TYPE;
typedef struct _EFI_OPEN_PROTOCOL_INFORMATION_ENTRY EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;
typedef struct _EFI_BOOT_SERVICES EFI_BOOT_SERVICES;

typedef VOID (*EFI_EVENT_NOTIFY)(EFI_EVENT Event, VOID* Context);

typedef EFI_STATUS (*EFI_RAISE_TPL)(EFI_TPL NewTpl);
typedef EFI_STATUS (*EFI_RESTORE_TPL)(EFI_TPL OldTpl);
typedef EFI_STATUS (*EFI_ALLOCATE_PAGES)(EFI_ALLOCATE_TYPE Type, UINTN MemoryType, UINTN Pages, EFI_PHYSICAL_ADDRESS* Memory);
typedef EFI_STATUS (*EFI_FREE_PAGES)(EFI_PHYSICAL_ADDRESS Memory, UINTN Pages);
typedef EFI_STATUS (*EFI_GET_MEMORY_MAP)(UINTN* MemoryMapSize, EFI_MEMORY_DESCRIPTOR* MemoryMap, UINTN* MapKey, UINTN* DescriptorSize, UINT32* DescriptorVersion);
typedef EFI_STATUS (*EFI_ALLOCATE_POOL)(UINTN PoolType, UINTN Size, VOID** Buffer);
typedef EFI_STATUS (*EFI_FREE_POOL)(VOID* Buffer);
typedef EFI_STATUS (*EFI_CREATE_EVENT)(UINT32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, VOID* NotifyContext, EFI_GUID* EventGroup, EFI_EVENT* Event);
typedef EFI_STATUS (*EFI_SET_TIMER)(EFI_EVENT Event, EFI_TIMER_DELAY Type, UINT64 TriggerTime);
typedef EFI_STATUS (*EFI_WAIT_FOR_EVENT)(UINTN NumberOfEvents, EFI_EVENT* Event, UINTN* Index);
typedef EFI_STATUS (*EFI_SIGNAL_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_CLOSE_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_CHECK_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_INSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE* Handle, EFI_GUID* Protocol, EFI_INTERFACE_TYPE InterfaceType, VOID* Interface);
typedef EFI_STATUS (*EFI_REINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE Handle, EFI_GUID* Protocol, VOID* OldInterface, VOID* NewInterface);
typedef EFI_STATUS (*EFI_UNINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE Handle, EFI_GUID* Protocol, VOID* Interface);
typedef EFI_STATUS (*EFI_HANDLE_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID* Protocol, VOID** Interface);
typedef EFI_STATUS (*EFI_REGISTER_PROTOCOL_NOTIFY)(EFI_GUID* Protocol, EFI_EVENT Event, VOID** Registration);
typedef EFI_STATUS (*EFI_LOCATE_HANDLE)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID* Protocol, VOID* SearchKey, UINTN* BufferSize, EFI_HANDLE* Buffer);
typedef EFI_STATUS (*EFI_LOCATE_DEVICE_PATH)(EFI_GUID* Protocol, EFI_DEVICE_PATH_PROTOCOL** DevicePath, EFI_HANDLE* Device);
typedef EFI_STATUS (*EFI_INSTALL_CONFIGURATION_TABLE)(EFI_GUID* Guid, VOID* Table);
typedef EFI_STATUS (*EFI_IMAGE_LOAD)(BOOLEAN BootPolicy, EFI_HANDLE ParentImageHandle, EFI_DEVICE_PATH_PROTOCOL* DevicePath, VOID* SourceBuffer, UINTN SourceSize, EFI_HANDLE* ImageHandle);
typedef EFI_STATUS (*EFI_IMAGE_START)(EFI_HANDLE ImageHandle, UINTN* ExitDataSize, CHAR16** ExitData);
typedef EFI_STATUS (*EFI_EXIT)(EFI_HANDLE ImageHandle, EFI_STATUS ExitStatus, UINTN ExitDataSize, CHAR16* ExitData);
typedef EFI_STATUS (*EFI_IMAGE_UNLOAD)(EFI_HANDLE ImageHandle);
typedef EFI_STATUS (*EFI_EXIT_BOOT_SERVICES)(EFI_HANDLE ImageHandle, UINTN MapKey);
typedef EFI_STATUS (*EFI_GET_NEXT_MONOTONIC_COUNT)(UINT64* Count);
typedef EFI_STATUS (*EFI_STALL)(UINTN Microseconds);
typedef EFI_STATUS (*EFI_SET_WATCHDOG_TIMER)(UINTN Timeout, UINT64 WatchdogCode, UINTN DataSize, CHAR16* WatchdogData);
typedef EFI_STATUS (*EFI_CONNECT_CONTROLLER)(EFI_HANDLE ControllerHandle, EFI_HANDLE* DriverImageHandle, EFI_DEVICE_PATH_PROTOCOL* RemainingDevicePath, BOOLEAN Recursive);
typedef EFI_STATUS (*EFI_DISCONNECT_CONTROLLER)(EFI_HANDLE ControllerHandle, EFI_HANDLE DriverImageHandle, EFI_HANDLE ChildHandle);
typedef EFI_STATUS (*EFI_OPEN_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID* Protocol, void** Interface, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle, UINT32 Attributes);
typedef EFI_STATUS (*EFI_CLOSE_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID* Protocol, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle);
typedef EFI_STATUS (*EFI_OPEN_PROTOCOL_INFORMATION)(EFI_HANDLE Handle, EFI_GUID* Protocol, EFI_OPEN_PROTOCOL_INFORMATION_ENTRY** EntryBuffer, UINTN* EntryCount);
typedef EFI_STATUS (*EFI_PROTOCOLS_PER_HANDLE)(EFI_HANDLE Handle, EFI_GUID*** ProtocolBuffer, UINTN* ProtocolBufferCount);
typedef EFI_STATUS (*EFI_LOCATE_HANDLE_BUFFER)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID* Protocol, VOID* SearchKey, UINTN* NoHandles, EFI_HANDLE** Buffer);
typedef EFI_STATUS (*EFI_LOCATE_PROTOCOL)(EFI_GUID* Protocol, VOID* Registration, VOID** Interface);
typedef EFI_STATUS (*EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE* Handle, ...);
typedef EFI_STATUS (*EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE* Handle, ...);
typedef EFI_STATUS (*EFI_CALCULATE_CRC32)(VOID* Data, UINTN DataSize, UINT32* Crc32);
typedef EFI_STATUS (*EFI_COPY_MEM)(VOID* Destination, VOID* Source, UINTN Length);
typedef EFI_STATUS (*EFI_SET_MEM)(VOID* Buffer, UINTN Size, UINT8 Value);
typedef EFI_STATUS (*EFI_CREATE_EVENT_EX)(UINT32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, VOID* NotifyContext, EFI_GUID* EventGroup, EFI_EVENT* Event);

struct _EFI_BOOT_SERVICES
{
    EFI_TABLE_HEADER Hdr;
    EFI_RAISE_TPL RaiseTPL;
    EFI_RESTORE_TPL RestoreTPL;
    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;
    EFI_CREATE_EVENT CreateEvent;
    EFI_SET_TIMER SetTimer;
    EFI_WAIT_FOR_EVENT WaitForEvent;
    EFI_SIGNAL_EVENT SignalEvent;
    EFI_CLOSE_EVENT CloseEvent;
    EFI_CHECK_EVENT CheckEvent;
    EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL HandleProtocol;
    VOID* Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
    EFI_LOCATE_HANDLE LocateHandle;
    EFI_LOCATE_DEVICE_PATH LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;
    EFI_IMAGE_LOAD LoadImage;
    EFI_IMAGE_START StartImage;
    EFI_EXIT Exit;
    EFI_IMAGE_UNLOAD UnloadImage;
    EFI_EXIT_BOOT_SERVICES ExitBootServices;
    EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
    EFI_STALL Stall;
    EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;
    EFI_CONNECT_CONTROLLER ConnectController;
    EFI_DISCONNECT_CONTROLLER DisconnectController;
    EFI_OPEN_PROTOCOL OpenProtocol;
    EFI_CLOSE_PROTOCOL CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;
    EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;
    EFI_CALCULATE_CRC32 CalculateCrc32;
    EFI_COPY_MEM CopyMem;
    EFI_SET_MEM SetMem;
    EFI_CREATE_EVENT_EX CreateEventEx;
};

#endif
