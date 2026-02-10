.PHONY: all clean

# Changer cette ligne en l'adapter à chaque TP
PROGS=maxminsum maxminsum2 maxminsum3 maxminsum4
CC=gcc
CFLAGS=
# Rien à changer à partir d'ici

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< 

%.s: %.c
	$(CC) -S $<

clean:
	rm -f $(PROGS) *.s
