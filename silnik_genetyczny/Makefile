OBJS = GAzagadnienie.o GAosobnik.o GAzakres.o funkcja.o dziedzina.o main.o brent.o mnbark.o macierz.o linmin.o powell.o
SRCS=brent.cpp mnbark.cpp macierz.cpp linmin.cpp powell.cpp
PROGRAM =       genetic
FLAGS = -O3 -pedantic -Wall
CC=g++



PROGRAM=genetic
all:$(PROGRAM)


$(PROGRAM):     $(OBJS)
		g++  $(OBJS) -o $(PROGRAM)
		@echo
# Jak narazie nie usuwam obiektów...
#		@rm -r *.o
#		@echo "Usuwam obiekty..."
		@echo 
		@echo "Kompilacja zakonczona pomyslnie"
		@echo

GAzagadnienie.o: GAzagadnienie.cpp
		@echo "Kompilacja GAzagadnienie.cpp..."
		g++ $(FLAGS) -c GAzagadnienie.cpp

GAzakres.o: GAzakres.cpp
		@echo "Kompilacja GAzakres.cpp..."
		g++ $(FLAGS) -c GAzakres.cpp

GAosobnik.o: GAosobnik.cpp
		@echo "Kompilacja GAosobnik.cpp..."
		g++ $(FLAGS) -c GAosobnik.cpp

main.o: main.cpp
		@echo "Kompilacja main.cpp..."
		g++ $(FLAGS) -c main.cpp

funkcja.o: funkcja.cpp
		@echo "Kompilacja funkcja.cpp..."
		g++ $(FLAGS) -c funkcja.cpp


dziedzina.o: dziedzina.cpp
		@echo "Kompilacja dziedzina.cpp..."
		g++ $(FLAGS) -c dziedzina.cpp

brent.o: brent.cpp
		@echo "Kompilacja brent.cpp..."
		$(CC) $(FLAGS) -c brent.cpp
macierz.o: macierz.cpp
		@echo "Kompilacja macierz.cpp..."
		$(CC) $(FLAGS) -c macierz.cpp
linmin.o: linmin.cpp
		@echo "Kompilacja linmin.cpp..."
		$(CC) $(FLAGS) -c linmin.cpp
mnbark.o: mnbark.cpp
		@echo "Kompilacja mnbark.cpp..."
		$(CC) $(FLAGS) -c mnbark.cpp
powell.o: powell.cpp
		@echo "Kompilacja powell.cpp..."
		$(CC) $(FLAGS) -c powell.cpp
