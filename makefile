all: coinMain coinMain.o coinGreedy.o

coinMain: coinMain.o coinGreedy.o 
	g++ -g coinMain.o coinGreedy.o -o coinMain

coinMain.o: coinMain.cpp
	g++ -c coinMain.cpp

coinGreedy.o: coinGreedy.cpp coinGreedy.h
	g++ -c coinGreedy.cpp
		

clean:	
	rm coinMain.o
	rm coinGreedy.o
