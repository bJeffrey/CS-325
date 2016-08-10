all: TSP

TSP: main.o 
	gcc -g -Wall -std=c99 -o TSP main.o -L/path/to/Libs -lm

main.o: main.c 
	gcc -g -Wall -std=c99 -c main.c -L/path/to/Libs -lm


clean:
	rm TSP
	rm main.o
