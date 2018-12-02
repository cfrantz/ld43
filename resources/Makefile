include ../toolchain.mk

.PHONY: clean 
.PRECIOUS: *.o

OUTS=level0.c level1.c temple1.c bgtiles.h cchars.h sprites.h

all: $(OUTS)

level0.c: maps.yaml
	python3 mklevels.py --bank 0 $< >$@
	cp $@ ../levels

level1.c: maps.yaml
	python3 mklevels.py --bank 1 $< >$@
	cp $@ ../levels

temple1.c: temple1.yaml
	python3 mklevels.py $< >$@
	cp $@ ../levels

cchars.h: tiles.yaml
	python3 mktiles.py --range 0x00-0x1f $< >$@

bgtiles.h: tiles.yaml
	python3 mktiles.py --range 0x80-0xff $< >$@

sprites.h: sprites.yaml
	python3 mktiles.py --range 0x00-0xff $< >$@

%.o: %.c
	$(CC) -Oi $< --add-source
	$(AS) $*.s

clean:
	@rm -fv $(OUTS)
