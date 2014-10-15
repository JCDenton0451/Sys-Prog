OBJECTS = code.o mylist.o stringfunc.o
CPPFLAGS = -g -Wall

prog: code.o mylist.o stringfunc.o
	gcc $(CPPFLAGS) -o prog $(OBJECTS)

code.o: code.c
	gcc $(CPPFLAGS) -c code.c

mylist.o: mylist.c mylist.h
	gcc $(CPPFLAGS) -c mylist.c

stringfunc.o: stringfunc.c stringfunc.h
	gcc $(CPPFLAGS) -c stringfunc.c