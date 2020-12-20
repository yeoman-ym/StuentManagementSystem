System:main.o menu.o student.o
	CC -o System main.o menu.o student.o

main.o:main.c student.h menu.h
	CC -c main.c -o main.o

menu.o:menu.c menu.h
	CC -c menu.c -o menu.o

student.o:student.c student.h
	CC -c student.c -o student.o

clean:
	rm -rf System main.o menu.o student.o
