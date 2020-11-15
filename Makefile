OUTPUTSPATH = build
MAIN_FILENAME = main
HEXFILE = tractor.ihx

SOURCES = \
$(MAIN_FILENAME).c \
config.c \
stm8s_gpio.c

RELS = $(addprefix $(OUTPUTSPATH)/,$(SOURCES:.c=.rel))

SDCC = sdcc
MACROS = -D__CSMC__ -DSTM8S003
PROCTYPE = -lstm8 -mstm8
CFLAGSLIB = -c
PROCESSOR = stm8s003f3
DEBUGPROBE = stlinkv2
FLASH = stm8flash

INCLUDES = \
-Ilibs/ \
-Ilibs/StdPeriph_Driver/inc/

vpath %.c libs/
vpath %.c libs/StdPeriph_Driver/src/

all: $(OUTPUTSPATH) $(HEXFILE)

$(HEXFILE): $(RELS)
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(RELS) -o $(OUTPUTSPATH)/
	-mv $(OUTPUTSPATH)/$(MAIN_FILENAME).ihx $(HEXFILE)

$(OUTPUTSPATH)/%.rel: %.c
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(CFLAGSLIB) $< -o $(OUTPUTSPATH)/

$(OUTPUTSPATH):
	mkdir $@

.PHONY: clean flash
clean:
	-rm -fR $(OUTPUTSPATH) $(HEXFILE)

flash:
	$(FLASH) -c$(DEBUGPROBE) -p$(PROCESSOR) -w $(HEXFILE)
