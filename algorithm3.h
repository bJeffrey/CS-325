#ifndef ALGORITHM3_H_
#define ALGORITHM3_H_

/*
Struct to hold all the values from the algorithm
*/
struct subarray{
    int lowIndex;
    int highIndex;
    int sum;
};

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




#endif // ALGORITHM3_H_
