CFILES=$(wildcard src/*.c)
OUTFILES=$(patsubst src/%.c,%,$(CFILES))
CFLAGS=-O3 -std=c99 -Wall -pedantic -W

all: $(OUTFILES)

%: src/%.c
	@echo "CC\t$<"
	@$(CC) $< -o bin/$@ $(CFLAGS)

clean:
	@rm -f bin/*
