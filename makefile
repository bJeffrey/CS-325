all: coinMain coinMain.o coinGreedy.o changedp.o

coinMain: coinMain.o coinGreedy.o changedp.o
	g++ -g coinMain.o coinGreedy.o changedp.o -o coinMain

coinMain.o: coinMain.cpp
	g++ -c coinMain.cpp

coinGreedy.o: coinGreedy.cpp coinGreedy.h
	g++ -c coinGreedy.cpp
	
changedp.o: changedp.cpp changedp.h
	g++ -c changedp.cpp

clean:	
	rm coinMain.o
	rm coinGreedy.o
	rm changedp.o