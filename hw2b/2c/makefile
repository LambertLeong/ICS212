out	: main2c.o username.o
	gcc main2c.o username.o -o out
main2c.o	:	main2c.c
	gcc -c main2c.c
username.o  :   username.c
	gcc -c username.c
clean:
	rm *.o out
