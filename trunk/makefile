OBJECTS = code.o mylist.o stringfunc.o
CPPFLAGS = -g -Wall

prog: code.o mylist.o 
        gcc $(CPPFLAGS) -o prog $(OBJECTS)
        
code.o: code.c
          gcc $(CPPFLAGS) -c code.c
          
mylist.o: mylist.c
          gcc $(CPPFLAGS) -c mylist.c
          
stringfunc.o: stringfunc.c          
          gcc $(CPPFLAGS) -c stringfunc.c