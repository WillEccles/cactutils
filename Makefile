CFILES=$(wildcard src/*.c)
OUTFILES=$(patsubst src/%.c,bin/%,$(CFILES))
CFLAGS=-O3 -Wall -pedantic -W

all: $(OUTFILES)

bin/%: src/%.c
	@echo "CC\t$<"
	@$(CC) $< -o $@ $(CFLAGS)

clean:
	@rm -f bin/*
