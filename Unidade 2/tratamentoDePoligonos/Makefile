#declaring variablse
CC=g++
CFLAGS=-c -Wall


# this target will compile all the file
all: main.o point.o retangulo.o poligono.o
	$(CC) $(CFAGS) main.o point.o retangulo.o poligono.o -o poli

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

point.o: point.cpp #point.h
	$(CC) $(CFLAGS) point.cpp

retangulo.o: retangulo.cpp #retangulo.h
	$(CC) $(CFLAGS) retangulo.cpp

poligono.o: poligono.cpp #poligono.h
	$(CC) $(CFLAGS) poligono.cpp

clean:
	rm -rf *.o poli
