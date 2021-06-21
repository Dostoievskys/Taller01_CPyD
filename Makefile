CFLAGS = -g3 -Wall
MKDIR = mkdir -p
LIBS = -lm
	
directorios: 
	$(MKDIR) build ruta/bin

main.o: directorios main.cpp
	g++ $(CFLAGS) -c main.cpp -o build/main.o

Funciones.o: directorios Funciones.h Funciones.cpp
	g++ $(CFLAGS) -c Funciones.cpp -o build/Funciones.o

all: clean main.o Funciones.o
	g++ $(CFLAGS) -o ruta/bin/programa build/main.o build/Funciones.o $(LIBS) 
	rm -fr build

clean: 
	rm -fr *.o programa ruta build

.DEFAULT_GOAL := all