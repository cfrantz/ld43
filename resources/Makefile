include ../toolchain.mk

.PHONY: clean 
.PRECIOUS: *.o

SRCS=
OBJS=$(SRCS:.c=.o)
ASMS=$(SRCS:.c=.s)

all: level0.c bgtiles.h sprites.h

level0.c: maps.yaml
	python3 mklevels.py $< >$@
	cp $@ ../levels

bgtiles.h: tiles.yaml
	python3 mktiles.py --range 0x80-0xff $< >$@

sprites.h: sprites.yaml
	python3 mktiles.py --range 0x00-0xff $< >$@

%.o: %.c
	$(CC) -Oi $< --add-source
	$(AS) $*.s

clean:
	@rm -fv $(OBJS) $(ASMS) *.a
