OBJECT = main
LIB = projectlib

LIBFILEPATH = libs
OUTPUTSPATH = build

LIBFILE = $(LIBFILEPATH)/$(LIB).lib
HEXFILE = $(OUTPUTSPATH)/$(OBJECT).ihx
SRCFILE = $(OBJECT).c

SDCC = sdcc
MACROS = -D__CSMC__ -DSTM8S003
PROCTYPE = -lstm8 -mstm8
PROCESSOR = stm8s003f3
DEBUGPROBE = stlinkv2
FLASH = stm8flash

INCLUDES = \
-I$(LIBFILEPATH) \
-I../STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver/inc/

all: $(OUTPUTSPATH) $(LIBFILE) $(SRCFILE)
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(SRCFILE) $(LIBFILE) -o $(OUTPUTSPATH)/

$(LIBFILE):
	make --no-print-directory -C $(LIBFILEPATH)

$(OUTPUTSPATH):
	mkdir $@

.PHONY: clean flash
clean:
	-rm -fR $(OUTPUTSPATH)
	make clean --no-print-directory -C $(LIBFILEPATH)

flash: $(HEXFILE)
	$(FLASH) -c$(DEBUGPROBE) -p$(PROCESSOR) -w $(HEXFILE)
