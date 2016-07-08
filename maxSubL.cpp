#include <iostream>
#include "algorithm1.h"

struct subarray maxSubL(int *arr, int j)
{
	//initialize struct and set all values to zero
	struct subarray returnSub;
	returnSub.lowIndex = 0;
	returnSub.highIndex = 0;
	returnSub.sum = 0;
	//all sum values must be zero, else it may give  false negative when comparing values
	int temp = 0;
	int sum = arr[0];
	for (int i = 0; i < j; i++)
	{
		//if adding the current element of the array increases temp, sum them
		if (arr[i] > temp + arr[i])
			temp = arr[i];
		else
			temp += arr[i];
		//test if current temp value is greater than maximum sum, if so, replace max sum and change inde value
		if (temp > returnSub.sum)
		{
			returnSub.sum = temp;
			returnSub.highIndex = i;
		}
		//change sub index
		if (temp == arr[i])
			returnSub.lowIndex = i;
	}
	//std::cout << "Maximum subarray sums to " << returnSub.sum << " from elements " << returnSub.lowIndex + 1 << " to " << returnSub.highIndex + 1 << "\n";
	return returnSub;
}
