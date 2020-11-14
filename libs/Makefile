LIBNAME = projectlib
LIBRARY = $(LIBNAME).lib

OUTPUTSPATH = build

SOURCES = \
config.c \
stm8s_gpio.c \
stm8s_i2c.c

RELS = $(addprefix $(OUTPUTSPATH)/,$(SOURCES:.c=.rel))

SDCC = sdcc
SDAR = sdar

INCLUDES = \
-I./ \
-I../ \
-I../../STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver/inc/

CFLAGSLIB = -c
SDARFLAGS = -rc

MACROS = -D__CSMC__ -DSTM8S003
PROCTYPE = -lstm8 -mstm8

vpath %.c
vpath %.c ../../STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver/src/

all: $(OUTPUTSPATH) $(LIBRARY)

$(LIBRARY) : $(SOURCES)

%.lib : $(RELS)
	$(SDAR) $(SDARFLAGS) $@ $(RELS)

$(OUTPUTSPATH)/%.rel: %.c
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(CFLAGSLIB) $< -o $(OUTPUTSPATH)/

$(OUTPUTSPATH):
	mkdir $@

.PHONY: clean
clean:
	-rm -fR $(OUTPUTSPATH)
	-rm -f $(LIBRARY)
