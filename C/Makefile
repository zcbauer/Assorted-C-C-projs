BIN = gcc
all: approx

approx: approxPi.c
	$(BIN) -o $@ $^

.PHONY: clean
clean:
	rm -f approx
