CFLAGS+=-Wall -Wextra -O3 -march=native -flto -llept -ltesseract -pthread 
SRCDIR=src

OBJFILES = fuptcha.o  img.o  pargs.o  score.o  tess.o  util.o

OBJS = $(addprefix $(SRCDIR)/, $(OBJFILES))

fuptcha: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) fuptcha
