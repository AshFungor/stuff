.PHONY = clean

example : example.cpp queue.o
	g++ example.cpp queue.cpp -o example

queue.o : queue.cpp
	g++ -c queue.cpp

clean:
	rm example queue.o