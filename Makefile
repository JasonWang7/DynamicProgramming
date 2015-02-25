CC =gcc
CFLAGS = -g -pedantic -Wall -std=c99 -D_POSIX_C_SOURCE=199309L
LDFLAGS =
TARGET = A3q4

default: all

all: prog

prog: $(TARGET).c
	$(CC) $(CFLAGS) $_ -o $(TARGET)

rebuild: clean A3q4

clean: 
	rm -f $(TARGET) *.o *.out
