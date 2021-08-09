OUTPUTSPATH = build
MAIN_FILENAME = main

MAINCFILE = $(MAIN_FILENAME).c
MAINHEXFILE = $(MAIN_FILENAME).ihx
HEXFILE = tractor.ihx
LIBFILE = library.lib

SOURCES = \
config.c \
stm8s_it.c \
stm8s_clk.c \
stm8s_gpio.c \
stm8s_i2c.c \
stm8s_tim4.c \
debugLeds.c \
delay.c \
i2cCommunication.c \
pca9685LedDriver.c

RELS = $(addprefix $(OUTPUTSPATH)/,$(SOURCES:.c=.rel))

SDCC = sdcc
SDAR = sdar
MACROS = -DSTM8S003
PROCTYPE = -lstm8 -mstm8
CFLAGSLIB = -c
LIBOPTION = -rc
PROCESSOR = stm8s003f3
DEBUGPROBE = stlinkv2
FLASH = stm8flash

INCLUDES = \
-Ilibs/ \
-Ilibs/StdPeriph_Driver/inc/

vpath %.c libs/
vpath %.c libs/StdPeriph_Driver/src/

all: $(OUTPUTSPATH) $(HEXFILE)

$(HEXFILE): $(OUTPUTSPATH)/$(LIBFILE)
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(MAINCFILE) $(LIBFILE) -L $(OUTPUTSPATH) -o $(OUTPUTSPATH)/
	-mv $(OUTPUTSPATH)/$(MAINHEXFILE) $(HEXFILE)

$(OUTPUTSPATH)/$(LIBFILE): $(RELS)
	$(SDAR) $(LIBOPTION) $(OUTPUTSPATH)/$(LIBFILE) $(RELS)

$(OUTPUTSPATH)/%.rel: %.c
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(CFLAGSLIB) $< -o $(OUTPUTSPATH)/

$(OUTPUTSPATH):
	mkdir $@

.PHONY: clean flash
clean:
	-rm -fR $(OUTPUTSPATH) $(HEXFILE)

flash:
	$(FLASH) -c$(DEBUGPROBE) -p$(PROCESSOR) -w $(HEXFILE)
