all: main main.o maxSubL.o algorithm1.o algorithm3.o

main: main.o maxSubL.o algorithm1.o algorithm3.o
	g++ -g main.o maxSubL.o algorithm1.o algorithm3.o -o main

main.o: main.cpp
	g++ -c main.cpp

maxSubL.o: maxSubL.cpp maxSubL.h
	g++ -c maxSubL.cpp 
	
algorithm1.o: algorithm1.cpp algorithm1.h
	g++ -c algorithm1.cpp 
	
algorithm3.o: algorithm3.cpp algorithm3.h
	g++ -c algorithm3.cpp 

clean:	
	rm main 
	rm main.o
	rm maxSubL.o
	rm algorithm1.o
	rm algorithm3.o
