ARCH = x86_64
VENDOR = unknown
SYSTEM = windows
TARGET = ${ARCH}-${VENDOR}-${SYSTEM}

CP = cp
MAKE = make
CC = clang
QEMU = qemu-system-${ARCH}

OVMF = /usr/share/ovmf/OVMF.fd

CFLAGS += \
	--target=${TARGET} \
	-nostdlib \
	-c

LDFLAGS += \
	--target=${TARGET} \
	-nostdlib \
	-Wl,-entry:efi_main \
	-Wl,-subsystem:efi_application \
	-fuse-ld=lld

INCLUDES = \
	-I./lib/std \
	-I./lib/efi \
	-I./lib/efi/protocols \
	-I./src/core

default: build

compile:
	${CC} ${CFLAGS} ${INCLUDES} -o ./obj/bootx64.o ./src/bootx64.c

link:
	${CC} ${LDFLAGS} -o ./bin/bootx64.efi ./obj/bootx64.o

deploy:
	${CP} ./bin/bootx64.efi ./mnt/EFI/BOOT/BOOTX64.EFI

start:
	${QEMU} -bios ${OVMF} -hda fat:rw:mnt

build:
	${MAKE} compile
	${MAKE} link

run:
	${MAKE} deploy
	${MAKE} start
