#Makefile
all: sum-nbo

sum-nbo: main.o file_reader.o
	g++ -o sum-nbo main.o file_reader.o

main.o: file_reader.h main.c
	g++ -c -o main.o main.c

file_reader.o: file_reader.h file_reader.c
	g++ -c -o file_reader.o file_reader.c

clean:
	rm -f sum-nbo
	rm -f *.o
