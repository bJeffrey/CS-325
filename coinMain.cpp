#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "coinGreedy.h"
//#include "coinDP.h"

int sizeArr(std::string file)
{
	//initialize temp string
	std::string temp;
	//Open file
	std::ifstream coinFile(file.c_str());
	int i = 1;
	//checks against the ']' character (relying on the proper formatting) to determine when to stop
	coinFile >> temp;
	while (temp[temp.length() - 1] != ']')
	{
		//continuously iterates for each number
		coinFile >> temp;
		i++;
	}
	return i;
}

void fillArr(int *v, std::string file, int i)
{
	//initialize temp string
	std::string temp;
	//set up character array to act as a transfer
	char trans[5];	//set to five as standard integer can be larger than 5 digits
	//Open file
	std::ifstream coinFile(file.c_str());
	coinFile >> temp;
	//assign digits to a char array
	for (int j = 1; j < temp.length() - 1; j ++)	//first number listed will have unneeded characters on both ends, thus those are not counted
		trans[j-1] = temp[j];
	//set v[0] to the numerical value written in the char array
	v[0] = atoi(trans); 
	for (int k = 1; k < i; k++)
	{
		//repeat, but writing the first character to trans (as it won't have the closed brace)
		coinFile >> temp;
		//std::cout << temp << "\n";
		for (int j = 0; j < temp.length() - 1; j ++)
			trans[j] = temp[j];
		v[k] = atoi(trans);
		for (int j = 0; j < temp.length() - 1; j ++)
			trans[j] = NULL;
	}
}

int main(int argc, char *argv[])
{
	//set up strings for input
	std::string file = argv[1];
	std::string arrInput;
	std::string AVal;
	//input validation
	if (!std::ifstream(file.c_str()))
	{
		std::cout << "File does not exist.\nPlease make sure to include the proper extension.\n";
		return 0;
	}
	
	//Open file
	std::ifstream coinFile(file.c_str());
	//determine the size neeed for arrays
	int i = sizeArr(file);
	//initialize arrays with newly determined i
	int v[i];
	int c[i];
	int count = 0;
	
	//set c to all zeros to avoid data errors
	for (int j = 0; j < i; j++)
		c[j] = 0;
	//call text reader function to fill arrays
	fillArr(v, file, i);
	
	//cycle through unneeded variables
	for (int j = 0; j < i; j ++)
		coinFile >> AVal;
	//collect A value into a string
	coinFile >> AVal;
	//create a temporary character array for AVal
	char temp[AVal.length()];
	//translate string holding a into an array of characters to be used in atoi
	for (int i = 0; i < AVal.length(); i++)
	{
		temp[i] = AVal[i];
	}
	//Set integer A
	int A = atoi(temp);
	count = coinGreedy(c,v,i,A);
	
	//change file name manually
	file[file.length() - 4] = 'c';
	file[file.length() - 3] = 'h';
	file[file.length() - 2] = 'a';
	file[file.length() - 1] = 'n';
	file += "ge.txt";
	
	//create file
	std::ofstream myfile;
	myfile.open(file.c_str());
	//write to file
	myfile << "Algorithm changeGreedy:\n";
	myfile << "[";	//place in braces at beginning and end
	for (int j = 0; j < i; j ++)
	{
		myfile << c[j];
		if (j != i - 1)
			myfile << ", ";
	}
	myfile << "]\n";
	myfile << count << "\n";
	//repeat for DP
	
	//set c back to zeros
	for (int j = 0; j < i; j++)
		c[j] = 0;
	//perform DP algorithm
	/*coinDP(c,v,i,A);
	//write to file
	myfile << "Algorithm changeDP:\n";
	myfile << "[";	//place in braces at beginning and end
	for (int j = 0; j < i; j ++)
	{
		myfile << c[j];
		if (j != i - 1)
			myfile << ", ";
	}
	myfile << "]\n";
	myfile << count << "\n";*/
	
	//close file
	myfile.close();
	
}