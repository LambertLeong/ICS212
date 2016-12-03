out	:	getfield.o project2main.o myinputfunctions.o llist.o project2header.h record.h llist.h
	g++ getfield.o project2main.o myinputfunctions.o llist.o -o out

project2main.o :  project2main.cpp
	g++ -c project2main.cpp
getfield.o :    getfield.cpp
	g++ -c getfield.cpp
myinputfunctions.o :    myinputfunctions.cpp
	g++ -c myinputfunctions.cpp
iofunctions.o :    iofunctions.c
	g++ -c iofunctions.c   
llist.o :    llist.cpp
	g++ -c llist.cpp    
debug :
	g++ -Ddebug -c getfield.cpp project2main.cpp myinputfunctions.cpp llist.cpp
	g++  getfield.o project2main.o myinputfunctions.o llist.o -o out    
clean	:
	rm *.o out
