CC = gcc
CFLAGS = -Wall -c

all : isort txtfind

isort : isort.o mains.o
	$(CC) isort.o mains.o -o isort

txtfind : txtfind.o maint.o
	$(CC) txtfind.o maint.o -o txtfind

isort.o : isort.c isort.h
	$(CC) $(CFLAGS) isort.c

mains.o : mains.c isort.h
	$(CC) $(CFLAGS) mains.c

txtfind.o : txtfind.c txtfind.h
	$(CC) $(CFLAGS) txtfind.c

maint.o : maint.c txtfind.h
	$(CC) $(CFLAGS) maint.c

.PHONY : all clean

clean :
	rm -f *.o isort txtfind
