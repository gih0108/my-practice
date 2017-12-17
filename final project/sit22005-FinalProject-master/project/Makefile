all: LinkedList Queue Stack additionalpoint Stock test_main  
	g++ -L. linkedlist.o queue.o stack.o test_list.o  -o test_list
	g++ -L. linkedlist.o queue.o stack.o additionalpoint.o -o adiitional.point
	g++ -L. linkedlist.o Stock.o  -o Stock
LinkedList: linkedlist.cpp
	g++ -std=c++11 -c linkedlist.cpp -o linkedlist.o

Queue: queue.cpp
	g++ -std=c++11 -c queue.cpp -o queue.o
	
Stack: stack.cpp
	g++ -std=c++11 -c stack.cpp -o stack.o
	
additionalpoint: additionalpoint.cpp
	g++ -std=c++11 -c additionalpoint.cpp -o additionalpoint.o
	
Stock: Stock.cpp
	g++ -std=c++11 -c Stock.cpp -o Stock.o
	
test_main: test_list.cpp
	g++ -std=c++11 -c test_list.cpp -o test_list.o


	
clean:
	rm *.o -f
	rm test_list
	rm additionalpoint
	rm Stock