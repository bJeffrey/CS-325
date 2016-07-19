#include <iostream>
#include "changedp.h"

using namespace std;

int changedp(int *c, int *v, int length_of_arrays, int A)
{

    //the minimal number of coins
    int m = 0;
    //the variable temp is used in the building of the table
    //int temp;

    //below is the table used to store values for the DP alogrithm
    int T[length_of_arrays+1][A+1];






//adds the value of the base case of 0 of the array v.
//the new array is val.
int val[length_of_arrays+1];
val[0] = 0;
for (int row = 1; row < length_of_arrays+1; row++)
    val[row] = v[row-1];


//the following loops build the table.
for(int row = 0; row < length_of_arrays+1; row++)
    {
        for(int col = 0; col < A+1; col++)
        {
            if(row == 0)
                T[row][col] = 0;
            else
            {
            int temp = col;
            T[row][col] = 0;
            if(col >= val[row])
            {
                T[row][col] = T[row][col] + 1;
                temp = temp - val[row];
                T[row][col] = T[row][col] + T[row][temp];
            }
            else
                T[row][col] = T[row-1][col];

            if (row-1 > 0)
                T[row][col] = std::min(T[row][col], T[row-1][col]);

            }

        }
    }

//this prints out the table that is constructed
//used for testing
/*
for(int row = 0; row < length_of_arrays+1; row++)
    {
        for(int col = 0; col < A+1; col++)
        {
            cout << T[row][col] << " ";
        }
            cout << endl;
    }
*/

//sets m or the min value to the correct value
m = T[length_of_arrays][A];

//find the number of coins needed
int row = length_of_arrays;
int col = A;

/*
This while loop finds the number of coins needed to make change

*/
while (col > 0)
{
    if (T[row][col] == T[row-1][col])
        row--;
    else
    {
        c[row-1]++;
        col = col - val[row];
    }

}

    return m;

};
