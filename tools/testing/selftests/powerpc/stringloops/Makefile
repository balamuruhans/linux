# SPDX-License-Identifier: GPL-2.0
# The loops are all 64-bit code
CFLAGS += -I$(CURDIR)

EXTRA_SOURCES := ../harness.c

build_32bit = $(shell if ($(CC) $(CFLAGS) -m32 -o /dev/null memcmp.c >/dev/null 2>&1) then echo "1"; fi)

TEST_GEN_PROGS := memcmp_64 memcmp harness memcmp64 strlen

$(OUTPUT)/memcmp64: memcmp_64.o memcmp.o ../harness.o
	$(CC) $(CFLAGS) -m64 -maltivec memcmp.o memcmp_64.o ../harness.o -o memcmp_64

$(OUTPUT)/memcmp_64: memcmp_64.S
	$(CC) $(CFLAGS) -m64 -maltivec -D__ASSEMBLY__ -o memcmp_64.o -c memcmp_64.S

$(OUTPUT)/memcmp: memcmp.c
	$(CC) $(CFLAGS) -m64 -maltivec -o memcmp.o -c memcmp.c

$(OUTPUT)/harness: $(EXTRA_SOURCES)
	$(CC) $(CFLAGS) -m64 -maltivec -o ../harness.o -c $(EXTRA_SOURCES)

ifeq ($(build_32bit),1)
$(OUTPUT)/memcmp_32: memcmp.c
$(OUTPUT)/memcmp_32: CFLAGS += -m32

TEST_GEN_PROGS += memcmp_32
endif

$(OUTPUT)/strlen: strlen.c string.c

ifeq ($(build_32bit),1)
$(OUTPUT)/strlen_32: strlen.c
$(OUTPUT)/strlen_32: CFLAGS += -m32

TEST_GEN_PROGS += strlen_32
endif

ASFLAGS = $(CFLAGS)

top_srcdir = ../../../../..
include ../../lib.mk

$(TEST_GEN_PROGS): $(EXTRA_SOURCES)
