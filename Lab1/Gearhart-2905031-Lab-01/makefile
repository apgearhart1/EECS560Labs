STUDENT_ID=2905031
exe: main.o Executive.o LinkedList.o Node.o
	g++ -g -Wall main.o Executive.o LinkedList.o Node.o -o exe

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -g -Wall -std=c++11 -c Executive.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -g -Wall -std=c++11 -c LinkedList.cpp

Node.o: Node.cpp Node.h
	g++ -g -Wall -std=c++11 -c Node.cpp

clean:
	rm *.o Executive LinkedList Node main

tar: clean
	mkdir $(STUDENT_ID)_eecs560_lab1
	cp LinkedList.cpp LinkedList.h Executive.h Executive.cpp Node.h Node.cpp data.txt main.cpp makefile $(STUDENT_ID)_eecs560_lab1
	tar cfzv $(STUDENT_ID)_eecs560_lab1.tar.gz $(STUDENT_ID)_eecs560_lab1
	-rm -rf $(STUDENT_ID)_eecs560_lab1
