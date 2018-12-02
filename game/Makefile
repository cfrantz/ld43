include ../toolchain.mk

.PHONY: clean 
.PRECIOUS: *.o

SRCS=entity.c
OBJS=$(SRCS:.c=.o) lfsr.o
ASMS=$(SRCS:.c=.s)

libgame.a: $(OBJS)
	$(AR) r $@ $(OBJS)

%.o: %.S
	$(AS) $<

%.o: %.c
	$(CC) -I.. -Oi $< --add-source
	$(AS) $*.s

clean:
	@rm -fv $(OBJS) $(ASMS) *.a
