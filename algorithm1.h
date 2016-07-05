#ifndef ALGORITHM1_H
#define ALGORITHM1_H
#include <iostream>
#include <fstream>
using namespace std;

struct subarray{
  int lowIndex;
  int highIndex;
  int sum;
};

struct subarray alg1Calculate(int *array, const int size);//Calculates the largest subarray in an array
int getArraySum(int *array, int startIdx, int endIdx);//gets the sum of an array between startIdx and endIdx
struct subarray alg2Calculate(int *array, const int size);//Calculates the largest subarray in an array








#endif
