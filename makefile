program: program.o 7seg.o
	gcc program.o 7seg.o -o program

program.o: program.c 7seg.h
	gcc -c program.c

7seg.o: 7seg.c 7seg.h
	gcc -c 7seg.c