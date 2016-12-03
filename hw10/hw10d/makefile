out	:	animal.o main.o cow.o bird.o animal.h cow.h bird.h
	g++ animal.o main.o cow.o bird.o -o out

main.o :  main.cpp
	g++ -c main.cpp
animal.o :    animal.cpp
	g++ -c animal.cpp
cow.o :    cow.cpp
	g++ -c cow.cpp
bird.o :    bird.cpp
	g++ -c bird.cpp
clean	:
	rm *.o out
