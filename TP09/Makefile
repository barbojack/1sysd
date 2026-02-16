.PHONY: all clean

# Changer cette ligne en l'adapter à chaque TP
PROGS=city
CC=gcc
CFLAGS=
# Rien à changer à partir d'ici

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.s: %.c
	$(CC) -S $<

clean:
	rm -f $(PROGS) *.
