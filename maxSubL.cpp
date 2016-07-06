#include <iostream>
#include "maxSubL.h"
#include "algorithm1.h"

struct subarray maxSubL(long int *arr, int j)
{
	struct subarray returnSub;
	returnSub.lowIndex = 0;
	returnSub.highIndex = 0;
	returnSub.sum = 0;
	int temp = 0;
	int sum = arr[0];
	for (int i = 0; i < j; i++)
	{
		if (arr[i] > temp + arr[i])
			temp = arr[i];
		else
			temp += arr[i];
		if (temp > max)
		{
			returnSub.sum = temp;		
			returnSub.highIndex = i;
		}
		if (temp == arr[i])
			returnSub.lowIndex = i;
	}
	std::cout << "Maximum subarray sums to " << returnSub.sum << " from elements " << returnSub.lowIndex + 1 << " to " << returnSub.highIndex + 1 << "\n";
	return returnSub;
}
