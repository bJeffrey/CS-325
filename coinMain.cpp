#include <iostream>
#include <fstream>
#include <cstring>
#include "coinGreedy.h"
//#include "coinDP.h"

int sizeArr(std::string arr)
{
	j = 1;	
	for (int i = 0; i < arr.length(); i++)
	{
		if (arr[i] = ',')
			j++;
	}
	return j;
}

void fillArr(int *v, std::string arr)
{
	int i = 1;
	int j = 0;
	while (arr[i] != ']')
	{
		if (isdigit(arr[i])
		{
			v[j] = atoi(arr[i]);
			j++;
		}
	}
}

int main(int argc, char *argv[])
{
	//set up strings for input
	std::string file;
	std::string arrInput;
	std::string AVal;
	//input validation
	if (!std::ifstream(file.c_str()))
	{
		std::cout << "File does not exist.\nPlease make sure to include the proper extension.\n";
		return 0;
	}
	//This method will only allow for one inputted array; I'll be adding in the ability to add more later
	std::ifstream coinFile(file.c_str());
	coinFile >> arrInput;
	int i = sizeArr(arrInput);
	int v[i];
	int c[i];
	coinFile >> AVal;
	int A = atoi(AVal);
	
}