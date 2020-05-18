#include "efi/efi.h"

EFI_HANDLE _ImageHandle;
EFI_SYSTEM_TABLE* _SystemTable;

EFI_STATUS clear()
{
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* output;
    EFI_STATUS status;

    output = _SystemTable->ConOut;
    status = output->ClearScreen(output);

    return status;
}

EFI_STATUS print(CHAR16* String)
{
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* output;
    EFI_STATUS status;

    output = _SystemTable->ConOut;
    status = output->OutputString(output, String);

    return status;
}

EFI_STATUS EFIAPI efi_main(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* SystemTable)
{
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL* input = SystemTable->ConIn;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* output = SystemTable->ConOut;
    EFI_INPUT_KEY key;
    EFI_STATUS status;
    UINTN waiting;

    _ImageHandle = ImageHandle;
    _SystemTable = SystemTable;

    clear();
    print(L"Hello, world!\r\n");
    print(L"Press any key to exit..\r\n");

    status = SystemTable->BootServices->WaitForEvent(
        1,
        &(input->WaitForKey),
        &waiting
    );

    if (status != EFI_SUCCESS)
    {
        print(L"Failed to wait for key\r\n");
    }

    print(L"Shutting down\r\n");

    SystemTable->RuntimeServices->ResetSystem(
        EfiResetShutdown,
        EFI_SUCCESS,
        0,
        NULL
    );

    return EFI_SUCCESS;
}
