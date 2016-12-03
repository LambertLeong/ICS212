hw9:
	javac hw9.java
	javah -jni hw9
	gcc -shared -fpic -o libhw9.so -I/usr/jdk/jdk1.7.0_51/include -I/usr/j2se/include/solaris hw9.c
run:
	java -Djava.library.path=. hw9
    

clean	:
	rm *.o out
