out	:	main.o tcpfunc.o tcp.h 
	gcc main.o tcpfunc.o -o out
main.o :  main.c
	gcc -c main.c
tcpfunc.o	:	tcpfunc.c
	gcc -c tcpfunc.c
clean	:
	rm *.o out
