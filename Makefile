System:main.o menu.o student.o dlist.o
	gcc -g -o System main.o menu.o student.o dlist.o -Wall 

main.o:main.c student.h menu.h
	gcc -g -c main.c -o main.o -Wall

menu.o:menu.c menu.h common.h
	gcc -g -c menu.c -o menu.o -Wall

student.o:student.c student.h common.h
	gcc -g -c student.c -o student.o -Wall

dlist.o:dlist.c dlist.h
	gcc -g -c dlist.c -o dlist.o -Wall

clean:
	rm -rf System main.o menu.o student.o dlist.o
