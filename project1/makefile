out	:	project1ui.o getfield.o functions.o project1main.o project1header.h record.h readbychar.o myinputfunctions.o iofunctions.o
	gcc project1ui.o getfield.o functions.o project1main.o readbychar.o myinputfunctions.o  iofunctions.o -o out
project1main.o :  project1main.c
	gcc -c project1main.c
project1ui.o	:	project1ui.c
	gcc -c project1ui.c
getfield.o :    getfield.c
	gcc -c getfield.c
readbychar.o :    readbychar.c
	gcc -c readbychar.c
functions.o :    functions.c
	gcc -c functions.c
myinputfunctions.o :    myinputfunctions.c
	gcc -c myinputfunctions.c
iofunctions.o :    iofunctions.c
	gcc -c iofunctions.c    
clean	:
	rm *.o out
