#Makefile

all: add-nbo

add-nbo: main.o
	gcc -o add-nbo main.o
main.o: main.c
	gcc -c -o main.o main.c
clean:
	rm -f add-nbo
	rm -f *.o

