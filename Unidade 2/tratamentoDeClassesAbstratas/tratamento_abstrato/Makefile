#declaring variables
CC=g++
CFLAGS=-c -Wall

#this target will compile all the file
all: main.o screen.o figurageometrica.o reta.o retangulo.o circulo.o
	$(CC) main.o screen.o figurageometrica.o reta.o retangulo.o circulo.o -o abs

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

screen.o: screen.cpp
	$(CC) $(CFLAGS) screen.cpp

figurageometrica.o: figurageometrica.cpp
	$(CC) $(CFLAGS) figurageometrica.cpp

reta.o: reta.cpp
	$(CC) $(CFLAGS) reta.cpp

retangulo.o: retangulo.cpp
	$(CC) $(CFLAGS) retangulo.cpp

circulo.o: circulo.cpp
	$(CC) $(CFLAGS) circulo.cpp

clean:
	rm -rf *.o abs
