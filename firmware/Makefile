A_DIR := /usr/share/ti/cgt-pru/lib

all: firmware

firmware: test.obj AM3359_PRU.cmd
	lnkpru -i$(A_DIR) test.obj AM3359_PRU.cmd -o=firmware

test.obj: test.c pru_defs.h
	clpru -O3 --c99 test.c

install: all
	install -m 444 firmware /lib/firmware
