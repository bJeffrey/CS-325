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
Description: 
Parameters:
Pre:
Post:
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
Description:
Parameters:
Pre:
Post:
*******************************************************************************/
struct subarray alg2Calculate(int *array, const int size){
  struct subarray A;
  int i, j;
  int currentSum = A.sum = array[0];
  A.lowIndex = 0;
  A.highIndex = 0;

  for(i = 0; i < size; i++){
    for(j = i; j < size; j++){
      if(i < j)
        currentSum = getArraySum(array, i, j);
      else
        currentSum = getArraySum(array, j, i);

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
