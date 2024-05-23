obj-m += my_dev.o
CC = gcc
PRODUCE_SRC = $(wildcard produce*.c)
PRODUCE_BIN = $(patsubst %.c, %, $(PRODUCE_SRC))
CONSUME_SRC = $(wildcard consume*.c)
CONSUME_BIN = $(patsubst %.c, %, $(CONSUME_SRC))

all: $(PRODUCE_BIN) $(CONSUME_BIN)
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

$(PRODUCE_BIN): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

$(CONSUME_BIN): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
	rm -f $(PRODUCE_BIN)
	rm -f $(CONSUME_BIN)

CONFIG_MODULE_SIG=n
