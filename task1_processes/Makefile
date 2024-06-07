CC = gcc
LD = gcc

CCFLAGS = -Wall
LDFLAGS = 

SRC = cw1a.c cw1b.c cw1c.c cw1d.c cw1e.c
OBJS = $(SRC:.c=.o)

HEADERS =

ARCHIVE = box

#----

all: cw1a cw1b cw1c cw1d cw1e

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<


cw1a: cw1a.o
	$(LD) $(LDFLAGS) -o $@ $^

cw1b: cw1b.o
	$(LD) $(LDFLAGS) -o $@ $^

cw1c: cw1c.o
	$(LD) $(LDFLAGS) -o $@ $^

cw1d: cw1d.o
	$(LD) $(LDFLAGS) -o $@ $^

cw1e: cw1e.o
	$(LD) $(LDFLAGS) -o $@ $^

run-cw1%: cw1%
	@echo "running the file...:"
	./$<


clean:
	@echo "cleaning the directory....:"
	@rm -f cw1a cw1b cw1c cw1d cw1e
	@rm -f cw1a.o cw1b.o cw1c.o cw1d.o cw1e.o

tar: 
	@echo "packing all the files....:"
	@tar cvzf $(ARCHIVE).tar.gz $(SRC) $(HEADERS) 


help:
	@echo "-------Spis komend:"
	@echo " "
	@echo "all -- compiles all the source files"
	@echo "clean -- deletes files created by Makefile"
	@echo "cw1x -- compiles requested file to the executable file called cw1x, where x is a letter from 'a' to 'e'."
	@echo "run-cw1x – runs (and compiles if its needed) requested file"
	@echo "tar – packs all the source files into archive: $(ARCHIVE).tar.gz"

