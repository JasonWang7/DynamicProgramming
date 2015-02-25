CC =gcc
CFLAGS = -g -pedantic -Wall -std=c99 -D_POSIX_C_SOURCE=199309L
LDFLAGS =
TARGET = A3q4

default: all

all: prog

prog: $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET)

rebuild: clean prog

clean: 
	rm -f $(TARGET) *.o *.out
