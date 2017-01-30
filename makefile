CPPFLAGS=-g -Wall -std=c++0x
CPP=g++

default: lox.o scanner.o
	$(CPP) $(CPPFLAGS) -o cpplox main.cpp lox.o scanner.o

lox.o: scanner.o
	$(CPP) $(CPPFLAGS) -c Lox.cpp

scanner.o:
	$(CPP) $(CPPFLAGS) -c Scanner.cpp

clean:
	rm -f cpplox
	rm -f *.o