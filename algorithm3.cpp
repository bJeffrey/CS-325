#include "algorithm3.h"
#include <stdio.h>
#include <limits.h>

//function finds the maximum of three integers
struct subarray max_val(struct subarray x,struct subarray y,struct subarray z)
{
    //stores the max value of the 3 cases
    struct subarray A;


    //if statements used to find the max value.
    if(x.sum > y.sum)
        A.sum = x.sum;
    else
        A.sum = y.sum;

    if( max_value < z.sum)
        A.sum = z.sum;

    return A;

}

//this is to find if the maximum sum crosses over two arrays.
/*
A[] - Array being passed to function
low - start of the array
mid - middle of array
high - end of the array
*/
struct subarray max_crossing(int A[], int low, int mid, int high)
{
    struct subarray A;


    int sum = 0; //this variable keeps track of the sums being calculated

    //INT_MIN sets the two below variables to the lowest value or  -2147483648
    int sum_left_side = INT_MIN;  //this is the sum of the left side
    int sum_right_side = INT_MIN; //This is the sum of the right side

    //this is a counter for the for loops
    int i;
    //This loop will check all the values from the left side.
    for(i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if(sum > sum_left_side)
            sum_left_side = sum;
    }

    sum = 0; //resets sum back to 0;

    //this loop checks the right hand side
    for(i = mid+1; i <= high; i++)
    {
        sum = sum + A[i];
        if (sum > sum_right_side)
            sum_right_side = sum;
    }

//transfers values to struct
    A.sum = sum_left_side + sum_right_side;
    A.highIndex = high;
    A.lowIndex = low;

//return the sum of the elements
    return A;
}

//this function is for finding the max of the array of a non crossing case
/*
A[] - Array being passed to function
low - start of the array
mid - middle of array
high - end of the array
*/
struct subarray max_array(int A[], int low, int high)
{
    //check the base case or 1 element
    if(low == high)
        return A[low];

    //this variable is for finding the middle value.
    int mid = (low + high)/2;

    //this will return the maximum value for the left, right and crossing case
    return max_val(max_array(A, low, mid),
                   max_array(A, mid+1, high),
                   max_crossing(A, low, mid, high)
                   );

}
