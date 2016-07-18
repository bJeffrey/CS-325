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


    //place the value 0 in the first column and row of the table
    for(int k=0; k<length_of_arrays+1; k++)
    {
        T[k][0]= 0;
    }
    for(int k=0; k<A+1; k++)
    {
        T[0][k]= k;
    }


//adds the value of the base case of 0 of the array v.
//the new array is val.
int val[length_of_arrays+1];
val[0] = 0;
for (int i = 1; i < length_of_arrays+1; i++)
    val[i] = v[i-1];


//the following loops build the table.
for(int j = 1; j < length_of_arrays+1; j++)
    {
        for(int i = 1; i < A+1; i++)
        {
            int temp = i;
            T[j][i] = 0;
            if(i >= val[j])
            {
                T[j][i] = T[j][i] + 1;
                temp = temp - val[j];
                T[j][i] = T[j][i] + T[j][temp];
            }
            else
                T[j][i] = T[j-1][i];

            if (j-1 > 0)
                T[j][i] = std::min(T[j][i], T[j-1][i]);
        }
    }

/*
//testing to see the table for error checking
cout << "val" << endl;
   for(int j = 0; j < length_of_arrays+1; j++)
    {
        for(int i = 0; i < A+1; i++)
        {
            cout << T[j][i] << " ";
        }
        cout << endl;
    }
cout << endl;
*/


//sets m or the min value to the correct value
m = T[length_of_arrays][A];
/*
std::cout << "m = " << m << std::endl;
cout << "length_of_arrays = " << length_of_arrays << endl;
cout << "A = " << A << endl;
cout << "T[length_pf_array][A] = " << T[length_of_arrays][A] << endl;
*/



for(int i = 0; i < length_of_arrays; i++)
{    c[i]=0;
}
int col = A;
int row = length_of_arrays;
/*
cout << "T[row][col] = " << T[row][col] << endl;
cout << "T[row-1][col] = " << T[row-1][col] << endl;
/*
cout << "row = " << row << endl;
cout << "col = " << col << endl;
*/
//finds the # of coins per size used
//cout << "T = " << T[row][col] << endl;

while(col > 0)
{

    if(T[row][col] == T[row-1][col])
    {
        row--;
    }
    else
    {
        c[row-1]++;
        col = col - val[row];
    }

    if(row == 0)
    {
        c[0]++;
        col--;
    }

/*
cout << "col = " << col << endl;
cout << "row = " << row << endl;
/*
cout << "val[0] = " << val[0] << endl;
cout << "val[1] = " << val[1] << endl;
cout << "val[2] = " << val[2] << endl;
cout << "val[3] = " << val[3] << endl;
cout << "val[4] = " << val[4] << endl;
cout << "val[5] = " << val[5] << endl;
/*
std::cout << "C[";
for(int i = 0; i < length_of_arrays; i++)
{
    std::cout << c[i] << ",";
}
std::cout << "]\n";
*/

}

/*
std::cout << "C[";
for(int i = 0; i < length_of_arrays; i++)
{
    std::cout << c[i] << ",";
}
std::cout << "]\n";
*/
    return m;

};

int coinGreedy(int *c, int *v, int i, int A)
{
	int count = 0;
	while (A > 0)
	{
		if (A >= v[i-1])
		{
			A -= v[i-1];
			c[i-1]++;
			count++;
		}
		else if(i > 0)
		{
			i--;
		}
		else
		{
			A -= v[i-1];
			c[i-1]++;
			count ++;
		}
    }


	return count;
}
