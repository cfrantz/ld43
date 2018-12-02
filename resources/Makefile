include ../toolchain.mk

.PHONY: clean 
.PRECIOUS: *.o

OUTS=level0.c level1.c bgtiles.h sprites.h

all: $(OUTS)

level0.c: maps.yaml
	python3 mklevels.py --bank 0 $< >$@
	cp $@ ../levels

level1.c: maps.yaml
	python3 mklevels.py --bank 1 $< >$@
	cp $@ ../levels

bgtiles.h: tiles.yaml
	python3 mktiles.py --range 0x80-0xff $< >$@

sprites.h: sprites.yaml
	python3 mktiles.py --range 0x00-0xff $< >$@

%.o: %.c
	$(CC) -Oi $< --add-source
	$(AS) $*.s

clean:
	@rm -fv $(OUTS)
