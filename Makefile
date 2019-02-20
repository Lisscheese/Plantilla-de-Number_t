# La siguiente no es necesariamente requerida, se agrega para
# mostrar como funciona.

.SUFFIXES: .o .c
.c.o:
	$(CC) -c $(CFLAGS) $<


# Macros

CXX = g++
CFLAGS = -g -Wall -O2
SRC = main.cpp  Number.hpp 
OBJ = main.o 


# Reglas expl�citas

all: ${OBJ}
	$(CXX) $(CFLAGS) -o main $(OBJ)

clean:
	$(RM) $(OBJ) main

# Reglas impl�citas
#Number.o: Number.cpp Number.hpp
main.o: main.cpp Number.hpp 

run: main.o  
	./main 