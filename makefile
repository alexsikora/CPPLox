CPPFLAGS=-g -Wall -std=c++0x
CPP=g++

default: lox.o
	$(CPP) $(CPPFLAGS) -o cpplox main.cpp lox.o

lox.o: 
	$(CPP) $(CPPFLAGS) -c Lox.cpp

clean:
	rm -f cpplox
	rm -f *.o