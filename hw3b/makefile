out	:	hw3ui.o getfield.o functions.o hw3bmain.o acountfunctions.h record.h readbychar.o myinputfunctions.o
	gcc hw3ui.o getfield.o functions.o hw3bmain.o readbychar.o myinputfunctions.o -o out
hw3bmain.o :  hw3bmain.c
	gcc -c hw3bmain.c
hw3ui.o	:	hw3ui.c
	gcc -c hw3ui.c
getfield.o :    getfield.c
	gcc -c getfield.c
readbychar.o :    readbychar.c
	gcc -c readbychar.c
functions.o :    functions.c
	gcc -c functions.c
myinputfunctions.o :    myinputfunctions.c
	gcc -c myinputfunctions.c
clean	:
	rm *.o out
