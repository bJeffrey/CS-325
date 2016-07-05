default: main.cpp algorithm1.cpp
	g++ -g main.cpp algorithm1.cpp -o main

clean:
	rm data.csv MSS_Problems.txt MSS_RESULTS.txt
