#include "algorithm1.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*******************************************************************************
Description: Computes the sum of an array
Parameters:
    array - array with values -100 through 100
    startIdx - index of the array to begin from
    endIdx   - endex of the array to end on
Pre: array populated.
Post: sum of values between startIdx and endIdx calculated
*******************************************************************************/
int getArraySum(int *array, int startIdx, int endIdx){
  int sum = 0;
  for(startIdx; startIdx <= endIdx; startIdx++)
  sum += array[startIdx];

  return sum;
}

/*******************************************************************************
Description: Finds the start and end endices of the maximum subarray in an array
             as well as the value of the sum.  Algorithm computes the sum of the
             subarray between every pair of indices
Parameters:
    array - array with random values -100 through 100
    size - size of the aray
Pre: array populated.  Function called from main
Post: startIdx found. endIdx found.  sum found.
*******************************************************************************/
struct subarray alg1Calculate(int *array, const int size){
  struct subarray A;
  int i, j;
  int currentSum = A.sum = array[0];
  A.lowIndex = 0;
  A.highIndex = 0;

  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++){
      if(i < j)
        currentSum = getArraySum(array, i, j);
      else
        currentSum = getArraySum(array, j, i);

      if(currentSum >= A.sum){
        A.sum = currentSum;
        if(i < j){
          A.lowIndex = i;
          A.highIndex = j;
        }
        else
          A.lowIndex = j;
          A.highIndex = i;
      }
    }
  }
  return A;
}

/*******************************************************************************
Description: Finds the start and end endices of the maximum subarray in an array
             as well as the value of the sum.  Algorithm notices that alg1Calculate
             calculates the same value several times.  To find the next sum,
             the next element of the array is added
Parameters:
    array - array with random values -100 through 100
    size - size of the aray
Pre: array populated.  Function called from main
Post: startIdx found. endIdx found.  sum found.
*******************************************************************************/
struct subarray alg2Calculate(int *array, const int size){
  struct subarray A;
  int i, j;
  int currentSum = A.sum = array[0];
  A.lowIndex = 0;
  A.highIndex = 0;

  for(i = 0; i < size; i++){
    currentSum = array[i];
    for(j = i; j < size; j++){
      if(i != j)
        currentSum += array[j];

      if(currentSum >= A.sum){
        A.sum = currentSum;
        A.lowIndex = i;
        A.highIndex = j;
      }
    }
  }
  return A;
}
  // getline(rand_num, mystring);
  // mystringstream << mystring;
  // mystringstream >> array[i];
  return A;
}

/*******************************************************************************
Description: Finds the start and end endices of the maximum subarray in an array
             as well as the value of the sum.  Algorithm notices that alg1Calculate
             calculates the same value several times.  To find the next sum,
             the next element of the array is added
Parameters:
    array - array with random values -100 through 100
    size - size of the aray
Pre: array populated.  Function called from main
Post: startIdx found. endIdx found.  sum found.
*******************************************************************************/
struct subarray alg2Calculate(int *array, const int size){
  struct subarray A;
  int i, j;
  int currentSum = A.sum = array[0];
  A.lowIndex = 0;
  A.highIndex = 0;

  for(i = 0; i < size; i++){
    currentSum = array[i];
    for(j = i; j < size; j++){
      if(i != j)
        currentSum += array[j];

      if(currentSum >= A.sum){
        A.sum = currentSum;
        A.lowIndex = i;
        A.highIndex = j;
      }
    }
  }
  return A;
}
  // getline(rand_num, mystring);
  // mystringstream << mystring;
  // mystringstream >> array[i];
