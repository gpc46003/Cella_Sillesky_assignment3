all: main

main: main.o DoublyLinkedList.o
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -o main main.o DoublyLinkedList.o

main.o: DoublyLinkedList.h main.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c DoublyLinkedList.cpp

clean:
	rm -rf main
	rm -rf *.o
