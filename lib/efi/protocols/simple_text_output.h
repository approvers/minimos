#ifndef __SIMPLE_TEXT_OUTPUT_H
#define __SIMPLE_TEXT_OUTPUT_H

#include "../efi.h"

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID {0x387477c2, 0x69c7, 0x11d2, {0x82, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}

struct _SIMPLE_TEXT_OUTPUT_MODE
{
    INT32 MaxMode;
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumn;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
};

typedef struct _SIMPLE_TEXT_OUTPUT_MODE SIMPLE_TEXT_OUTPUT_MODE;
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (*EFI_TEXT_RESET)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, BOOLEAN ExtendedVerification);
typedef EFI_STATUS (*EFI_TEXT_STRING)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, CHAR16* String);
typedef EFI_STATUS (*EFI_TEXT_TEST_STRING)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, CHAR16* String);
typedef EFI_STATUS (*EFI_TEXT_QUERY_MODE)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN ModeNumber, UINTN* Columns, UINTN* Rows);
typedef EFI_STATUS (*EFI_TEXT_SET_MODE)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN ModeNumber);
typedef EFI_STATUS (*EFI_TEXT_SET_ATTRIBUTE)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN Attribute);
typedef EFI_STATUS (*EFI_TEXT_CLEAR_SCREEN)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This);
typedef EFI_STATUS (*EFI_TEXT_SET_CURSOR_POSITION)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN Column, UINTN Row);
typedef EFI_STATUS (*EFI_TEXT_ENABLE_CURSOR)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, BOOLEAN Visible);

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
    EFI_TEXT_TEST_STRING TestString;
    EFI_TEXT_QUERY_MODE QueryMode;
    EFI_TEXT_SET_MODE SetMode;
    EFI_TEXT_SET_ATTRIBUTE SetAttribute;
    EFI_TEXT_CLEAR_SCREEN ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE* Mode;
};

#endif
