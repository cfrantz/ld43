
NESLIB=/usr/local/cc65/share/cc65/lib/nes.lib

SRCS=main.c chars.c
OBJS=$(SRCS:.c=.o)
ASMS=$(SRCS:.c=.s)
MAPPER=mappers/mmc3
LIBS=$(MAPPER)/libinit.a util/libutil.a game/libgame.a levels/liblevels.a
SUBDIRS=resources levels util game $(MAPPER)

all: $(SUBDIRS) ld43.nes
$(SUBDIRS):
	$(MAKE) -C $@

%.o: %.c
	cc65 -Oi $< --add-source
	ca65 $*.s

ld43.nes: $(OBJS) $(LIBS)
	ld65 -C $(MAPPER)/nes.cfg -vm --mapfile ld43.map -o $@ \
		$(OBJS) \
		$(LIBS) \
		$(NESLIB)

clean:
	@find . -name "*.[oas]" | xargs rm

realclean: clean
	@find . -name "*.nes" -o -name "*.map" | xargs rm

.PHONY: clean all $(SUBDIRS)
.PRECIOUS: *.o
all: $(SUBDIRS) ld43.nes
