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


/*
Struct to hold all the values from the algorithm
*/

//function finds the maximum of three integers
struct subarray max_val(struct subarray x,struct subarray y,struct subarray z);


//this is to find if the maximum sum crosses over two arrays.
/*
A[] - Array being passed to function
low - start of the array
mid - middle of array
high - end of the array
*/
struct subarray max_crossing(int A[], int low, int mid, int high);

//this function is for finding the max of the array of a non crossing case
/*
A[] - Array being passed to function
low - start of the array
mid - middle of array
high - end of the array
*/
struct subarray max_array(int A[], int low, int high);













#endif
