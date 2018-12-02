include ../toolchain.mk

.PHONY: clean 
.PRECIOUS: *.o

SRCS=screen.c level0.c level1.c temple1.c
OBJS=$(SRCS:.c=.o) util.o
ASMS=$(SRCS:.c=.s)

liblevels.a: $(OBJS)
	$(AR) r $@ $(OBJS)

util.o: util.S
	$(AS) $<

%.o: %.c
	$(CC) -I.. -Oi $< --add-source
	$(AS) $*.s

clean:
	@rm -fv $(OBJS) $(ASMS) *.a
