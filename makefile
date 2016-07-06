all: testMain testMain.o maxSubL.o

testMain: testMain.o maxSubL.o 
	g++ -g testMain.o maxSubL.o -o testMain

testMain.o: testMain.cpp
	g++ -c testMain.cpp

maxSubL.o: maxSubL.cpp maxSubL.h
	g++ -c maxSubL.cpp
		

clean:	
	rm testMain.o
	rm maxSubL.o
