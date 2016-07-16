#include "changedp.h"
#include <iostream>

using namespace std;

//see changedp.h for details.
void changedp(int *c, int *v, int length_of_arrays, int A)
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
                T[j][i] = min(T[j][i], T[j-1][i]);
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
cout << "m = " << m << endl;



for(int i = 0; i < length_of_arrays; i++)
{
    c[i]=0;
}
int i = A;
int j = length_of_arrays-1;


//finds the # of coins per size used
while(i > 0)
{
    if(T[j+1][i] == T[j][i])
        {
        c[j-1]++;
        j--;
        }
    else
        c[j]++;

        i=i-v[j];
}

cout << "C[";
for(int i = 0; i < length_of_arrays; i++)
{
    cout << c[i] << ",";
}
cout << "]\n";

};


