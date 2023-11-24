PROJECT_NAME = tractor
OUTPUTS_PATH = build
MAIN_FILENAME = main

MAIN_C_FILE = $(MAIN_FILENAME).c
MAIN_HEX_FILE = $(MAIN_FILENAME).ihx
HEX_FILE = $(PROJECT_NAME).ihx
LIB_FILE = library.lib

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
pca9685LedDriver.c \
buttons.c

RELS = $(addprefix $(OUTPUTS_PATH)/,$(SOURCES:.c=.rel))

SDCC = sdcc
SDAR = sdar
MACROS = -DSTM8S003
PROCTYPE = -lstm8 -mstm8
C_FLAGS_LIB = -c
LIB_OPTION = -rc
PROCESSOR = stm8s003f3
DEBUG_PROBE = stlinkv2
FLASH = stm8flash

INCLUDES = \
-Ilibs/ \
-Ilibs/StdPeriph_Driver/inc/

vpath %.c libs/
vpath %.c libs/StdPeriph_Driver/src/

all: $(OUTPUTS_PATH) $(OUTPUTS_PATH)/$(HEX_FILE)

$(OUTPUTS_PATH)/$(HEX_FILE): $(OUTPUTS_PATH)/$(LIB_FILE)
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(MAIN_C_FILE) $(LIB_FILE) -L $(OUTPUTS_PATH) -o $(OUTPUTS_PATH)/
	-mv $(OUTPUTS_PATH)/$(MAIN_HEX_FILE) $(OUTPUTS_PATH)/$(HEX_FILE)

$(OUTPUTS_PATH)/$(LIB_FILE): $(RELS)
	$(SDAR) $(LIB_OPTION) $(OUTPUTS_PATH)/$(LIB_FILE) $(RELS)

$(OUTPUTS_PATH)/%.rel: %.c
	$(SDCC) $(MACROS) $(PROCTYPE) $(INCLUDES) $(C_FLAGS_LIB) $< -o $(OUTPUTS_PATH)/

$(OUTPUTS_PATH):
	mkdir $@

.PHONY: clean flash
clean:
	-rm -fR $(OUTPUTS_PATH)

flash:
	$(FLASH) -c$(DEBUG_PROBE) -p$(PROCESSOR) -w $(OUTPUTS_PATH)/$(HEX_FILE)
