#ifndef CHANGEDP_H_INCLUDED
#define CHANGEDP_H_INCLUDED


/******************************
**Input:
** c is the coin combination of the lowest combanation
** v are the denomonations of coins in array form i.e. [1,3,5,7]
** length_of_arrays is how many different coin types. i.e. for the above example length_of_array equals 4
** A is the amount of desired change.
**
**Output:
** c is the only variable that will be altered.
*******************************/
void changedp(int *c, int *v, int length_of_arrays, int A);


#endif // CHANGEDP_H_INCLUDED
