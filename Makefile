CFLAGS=-O -Wall -Werror

CFILES	:= $(wildcard *.c)
OFILES	:= $(patsubst %.c,%.o,$(CFILES))
TARGETS	:= emirp

.PHONY: all clean

all: emirp

# remove -DUSEGMP and -lgmp unless you use gmp
emirp: reverse.c reverse.h emirp.c
	clang $(CFLAGS) -DUSEGMP -c reverse.c
	clang $(CFLAGS) -lgmp reverse.o emirp.c -o emirp

emirp.pdf: emirp.tex
	latexmk -pdf emirp

clean:
	$(RM) $(OFILES) $(TARGETS)
	latexmk -C emirp
