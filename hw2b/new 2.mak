makehw2	:	 mainhw2.o
	gcc mainhw2.o -o makehw2
mainhw2.o	:	mainhw2.c
	gcc -c mainhw2.c
halfstring.o	:	halfstring.c
	gcc -c halfstring.c
clean:
	rm *.o makehw2