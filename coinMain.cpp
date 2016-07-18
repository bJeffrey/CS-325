#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "coinGreedy.h"
#include "changedp.h"

int sizeArr(std::string temp)
{
	int i = 1;
	for (int j = 0; j < temp.length(); j++)
	{
		if (temp[j] == ',')
			i++;
	}
	return i;
}

void fillArr(int *v, std::string temp)
{
	//the largest number available for a standard integer is five digits
	char trans[5];
	int i = 0;
	int k = 0;
	//check string for numbers using conditional statements
	for (int j = 0; j < temp.length(); j++)
	{
		if (isdigit(temp[j]))
		{
			//transcribes numbers into trans array
			trans[k] = temp[j];
			k++;
		}
		//detects end in number
		else if (temp[j] == ',' || temp[j] == ']')
		{
			//when a new number is finished being transcribed, place it into v using atoi
			v[i] = atoi(trans);
			i++;
			for (int l = 0; l < 5; l++)
				trans[l] = NULL;
			k = 0;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "You have entered incorrect input for the program call, please try again.\n";
		return 0;
	}
	//set up strings for input
	std::string file = argv[1];
	std::string arrInput;
	std::string AVal;
	std::string control;
	std::string fileChange;
	//input validation
	if (!std::ifstream(file.c_str()))
	{
		std::cout << "File does not exist.\nPlease make sure to include the proper extension.\n";
		return 0;
	}
	
	fileChange = file;
	//change file name manually
	fileChange[file.length() - 4] = 'C';
	fileChange[file.length() - 3] = 'h';
	fileChange[file.length() - 2] = 'a';
	fileChange[file.length() - 1] = 'n';
	fileChange += "ge.txt";
	//create csv file
	std::string CSV = file;
	//change file name manually
	CSV[file.length() - 3] = 'c';
	CSV[file.length() - 2] = 's';
	CSV[file.length() - 1] = 'v';
	//Open file
	std::ifstream coinFile(file.c_str());
	//create file
	std::ofstream myfile;
	myfile.open(fileChange.c_str());
	//create csv
	std::ofstream fileCSV;
	fileCSV.open(CSV.c_str());
	
	while (getline(coinFile, control))
	{
		//determine the size neeed for arrays
		int i = sizeArr(control);
		//initialize arrays with newly determined i
		int *v = new int[i];
		int c[i];
		int count = 0;
		
		//set c to all zeros to avoid data errors
		for (int j = 0; j < i; j++)
			c[j] = 0;
		//call text reader function to fill arrays
		fillArr(v, control);
		getline(coinFile, AVal);
		/*//create a temporary character array for AVal
		char temp[AVal.length()];
		//translate string holding a into an array of characters to be used in atoi
		for (int i = 0; i < AVal.length(); i++)
		{
			temp[i] = AVal[i];
		}*/
		//Set integer array A
		int k = sizeArr(AVal);
		int *A = new int[k];
		fillArr(A, AVal);
		
		//set up CSV formatting
		fileCSV << "A values:,";
		for (int l = 0; l < k; l++)
		{
			fileCSV << A[l] << ",";
		}
		
		//CSV formatting
		fileCSV << "\nc values by greedy:,";
		
		//calculate by greedy
		for (int l = 0; l < k; l++)
		{
			count = coinGreedy(c,v,i,A[l]);
			//write to file
			myfile << "Algorithm changeGreedy:\n";
			myfile << "[";	//place in braces at beginning and end
			for (int j = 0; j < i; j++)
			{
				myfile << c[j];
				if (j != i - 1)
					myfile << ", ";
			}
			myfile << "]\n";
			myfile << count << "\n";
			
			//write to CSV
			fileCSV << count << ",";
			
			//set c back to zeros
			for (int j = 0; j < i; j++)
				c[j] = 0;
		}
		
		//CSV formatting 
		fileCSV << "\nc values by DP:,";
		//repeat for DP
		for (int l = 0; l < k; l++)
		{
			//perform DP algorithm
			/*
			i is equal to the number of different types of coins being used. i=5
			c is an array to store the coins needs to be in format c[5] = {0,0,0,0,0};
			v are the values of the coins being used. SHould look like this v[5] = {1,5,10,15,25}
			A is the desired change amount. should look like this A=37;
			*/
			count = changedp(c,v,i,A[l]);
			//std::cout << "Test2\n";
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
			myfile << count << "\n";
			
			//write to CSV
			fileCSV << count << ",";
			
			//set c back to zeros
			for (int j = 0; j < i; j++)
				c[j] = 0;
		}
		fileCSV << "\n";
		
		//close file
		delete v;
		delete A;
	}
	myfile.close();
	fileCSV.close();
}
