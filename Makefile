CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = sum_nbo

all: $(TARGET)

$(TARGET): main.o file_reader.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o file_reader.o

main.o: main.c file_reader.h
	$(CC) $(CFLAGS) -c main.c

file_reader.o: file_reader.c file_reader.h
	$(CC) $(CFLAGS) -c file_reader.c

clean:
	rm -f $(TARGET) *.o
