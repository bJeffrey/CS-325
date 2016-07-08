#include "algorithm1.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#define RAND_NUM_SIZE 60000
#define ALG_1_SIZE_LIMIT 750
#define ALG_1_STEP 5
#define ALG_2_SIZE_LIMIT 16000
#define ALG_2_STEP 150
#define ALG_3_SIZE_LIMIT 60000
#define ALG_3_STEP 100
#define ALG_3_DIVIDE 10
#define ALG_4_SIZE_LIMIT 60000
#define ALG_4_STEP 100
#define ALG_4_DIVIDE 150

using namespace std;

/*******************************************************************************
Description: Creates saves the results of calculating subarray into MSS_RESULTS.txt
Parameters:
size - size of the array
subarray - lowIndex, highIndex, and sum of the subarray
results - .txt file to store the results
Pre: Function called from main
Post: .csv and .txt files created, .txt file populated, both files closed
*******************************************************************************/
void saveResults(int i, struct subarray A, int *array, ofstream &results){
  results << "When the size of the array is " << i + 1 << ", the sum of the subarray is " << A.sum << " and the corresponding array is as follows:\n";

  for(A.lowIndex; A.lowIndex <= A.highIndex; A.lowIndex++)
    results << array[A.lowIndex] << " ";

  results << "\n\n";
}

/*******************************************************************************
Description: Controls runtime calculation for algorithm 1.  Has complexity
            O(n^3 - 1)
Parameters:
    rand_num - .txt file of random numbers in domain [-100, 100]
    data - .csv file for runtime data to be written to
Pre: Function called from main with .txt populated
Post: Maximum subarray found using algorithm 1.  Runtime data written to .csv file
*******************************************************************************/
void alg1Control(ifstream &rand_num, ofstream &data, ofstream &results){
  int i, j;
  float timer = 0.0;
  clock_t t;
  struct subarray A;

  cout << "Calculating subarray using algorithm 1...\n";
  results << "Results for Algorithm 1 are as follows:\n\n";

  for(i = 0; i < ALG_1_SIZE_LIMIT; i += ALG_1_STEP)
    data << i << ",";
  data << "\n";

  for(i = 0; i < ALG_1_SIZE_LIMIT; i += ALG_1_STEP){
    int array[i + 1];

    for(j = 0; j <= i; j++)
      rand_num >> array[j];

    t = clock();
    A = alg1Calculate(array, i + 1);
    t = clock() - t;
    timer += ((float)t)/CLOCKS_PER_SEC;

    saveResults(i, A, array, results);

    data << ((float)t)/CLOCKS_PER_SEC << ",";

    if( timer >= 5.0){
      cout << "Gathering data for algorithm 1...\n";
      timer = 0.0;
    }

    rand_num.clear();
    rand_num.seekg(0, ios::beg);
  }
  data << "\n\n";
  results << "\n\n";
}


/*******************************************************************************
Description: Controls runtime calculation for algorithm 2.  Has complexity O(n^2)
Parameters:
    rand_num - .txt file of random numbers in domain [-100, 100]
    data - .csv file for runtime data to be written to
Pre: Function called from main with .txt populated
Post: Maximum subarray found using algorithm 1.  Runtime data written to .csv file
*******************************************************************************/
void alg2Control(ifstream &rand_num, ofstream &data, ofstream &results){
  int i, j;
  float timer = 0.0;
  clock_t t;
  struct subarray A;

  cout << "Calculating subarray using algorithm 2...\n";
  results << "Results for Algorithm 2 are as follows:\n\n";

  for(i = 0; i < ALG_2_SIZE_LIMIT; i += ALG_2_STEP)
    data << i << ",";
  data << "\n";

  for(i = 0; i < ALG_2_SIZE_LIMIT; i += ALG_2_STEP){
    int array[i + 1];

    for(j = 0; j <= i; j++)
      rand_num >> array[j];

    t = clock();
    A = alg2Calculate(array, i + 1);
    t = clock() - t;
    timer += ((float)t)/CLOCKS_PER_SEC;

    saveResults(i, A, array, results);

    data << ((float)t)/CLOCKS_PER_SEC << ",";

    if( timer >= 5.0){
      cout << "Gathering data for algorithm 2...\n";
      timer = 0.0;
    }

    rand_num.clear();
    rand_num.seekg(0, ios::beg);
  }
  data << "\n\n";
  results << "\n\n";
}

/*******************************************************************************
Description: Controls runtime calculation for algorithm 3
Parameters:
    rand_num - .txt file of random numbers in domain [-100, 100]
    data - .csv file for runtime data to be written to
Pre: Function called from main with .txt populated
Post: Maximum subarray found using algorithm 1.  Runtime data written to .csv file
*******************************************************************************/
void alg3Control(ifstream &rand_num, ofstream &data, ofstream &results){
  int i, j;
  float timer = 0.0;
  clock_t t;
  struct subarray A;

  cout << "Calculating subarray using algorithm 3...\n";
  results << "Results for Algorithm 3 are as follows:\n\n";

  for(i = 0; i < ALG_3_SIZE_LIMIT; i += ALG_3_STEP)
    data << i << ",";
  data << "\n";

  for(i = 0; i < ALG_3_SIZE_LIMIT; i += ALG_3_STEP){
    int array[i + 1];

    for(j = 0; j <= i; j++)
      rand_num >> array[j];



    t = clock();
    for(int k = 0; k < ALG_3_DIVIDE; k++){
      A = max_array(array, 0, i);
    }
    t = clock() - t;
    timer += ((float)t)/CLOCKS_PER_SEC;

    saveResults(i, A, array, results);

    data << (((float)t)/CLOCKS_PER_SEC)/ALG_3_DIVIDE << ",";

    if( timer >= 5.0){
      cout << "Gathering data for algorithm 3...\n";
      timer = 0.0;
    }

    rand_num.clear();
    rand_num.seekg(0, ios::beg);
  }
  data << "\n\n";
  results << "\n\n";
}

/*******************************************************************************
Description: Controls runtime calculation for algorithm 4
Parameters:
    rand_num - .txt file of random numbers in domain [-100, 100]
    data - .csv file for runtime data to be written to
Pre: Function called from main with .txt populated
Post: Maximum subarray found using algorithm 1.  Runtime data written to .csv file
*******************************************************************************/
void alg4Control(ifstream &rand_num, ofstream &data, ofstream &results){
  int i, j;
  float timer = 0.0;
  clock_t t;
  struct subarray A;

  cout << "Calculating subarray using algorithm 4...\n";
  results << "Results for Algorithm 4 are as follows:\n\n";

  for(i = 0; i < ALG_4_SIZE_LIMIT; i += ALG_4_STEP)
    data << i << ",";
  data << "\n";

  for(i = 0; i < ALG_4_SIZE_LIMIT; i += ALG_4_STEP){
    int array[i + 1];

    for(j = 0; j <= i; j++)
      rand_num >> array[j];

    t = clock();
    for(int k = 0; k < ALG_4_DIVIDE; k++){
      A = maxSubL(array, i + 1);
    }
    t = clock() - t;



    timer += ((float)t)/CLOCKS_PER_SEC;

    saveResults(i, A, array, results);

    data << ( ( (float)t)/CLOCKS_PER_SEC)/ALG_4_DIVIDE << ",";

    if( timer >= 5.0){
      cout << "Gathering data for algorithm 4...\n";
      timer = 0.0;
    }

    rand_num.clear();
    rand_num.seekg(0, ios::beg);
  }
  data << "\n\n";
  results << "\n\n";
}


/*******************************************************************************
Description: Creates .txt and .csv files and populates .txt with random ints
Parameters: None
Pre: Function called from main
Post: .csv and .txt files created, .txt file populated, both files closed
*******************************************************************************/
void makeMyFiles(){

  int i;
  ofstream rand_num, data, results;
  rand_num.open ("MSS_Problems.txt");
  data.open("data.csv");
  results.open("MSS_RESULTS.txt");

  if(!rand_num.is_open() || !data.is_open()){
    cout << "Failed to create files.\n";
    return;
  }

  for(i = 0; i < RAND_NUM_SIZE; i++)
    rand_num << rand() % 201 + (-100) << " ";

  rand_num.close();
  data.close();
  results.close();
}

/*******************************************************************************
Description: Controls flow of control for running 4 algorithms that find the
             max subarray from an array
Parameters: None
Pre: None
Post: Runtime data from all 4 algorithms recorded and saved to .csv file
*******************************************************************************/
int main(){
  srand(time(NULL));
  makeMyFiles();

  int i;
  string mystring;
  ifstream rand_num ("MSS_Problems.txt");
  ofstream data ("data.csv");
  ofstream results ("MSS_RESULTS.txt");

  if(!rand_num.is_open() || !data.is_open()){
    cout << "Failed to open files.\n";
    return 0;
  }

  alg1Control(rand_num, data, results);
  alg2Control(rand_num, data, results);
  alg3Control(rand_num, data, results);
  alg4Control(rand_num, data, results);

  rand_num.close();
  data.close();
  results.close();

  cout << "Program ending... \n";
  return 0;
}
