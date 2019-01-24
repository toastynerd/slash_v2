SRC_DIR = src
LIB = -lSDL2 -lSDL2_image
CFLAGS = -Wall
INC = -Iinclude
PREFIX ?= /usr/bin

export LIB CFLAGS INC

.PHONY: slash clean install

slash:
	$(MAKE) -C $(SRC_DIR)
	mkdir -p build
	mv $(SRC_DIR)/slash build/slash

install:
	cp bin/slash $(PREFIX)/slash

clean:
	$(MAKE) -C $(SRC_DIR) clean
	rm -rf build
