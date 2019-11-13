IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm -lpthread

_DEPS = master_slave.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = svd.o disp_mat.o mul_mat.o pnmio.o error.o mythread.o trans_mat.o master.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

master: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ master *.bin

