#include "coin.h"

struct coin
{
	//make sure to initialize the c and v arrays at creation
	
	//c is the number of each denomination, i.e., if you have three
	//coins of v0, and two coins of v1, c[0] = 3. c[1] = 2
	int c[];
	//v is the denomination of each coin, in acending order, i.e.,
	//if you have denominations of 1, 5 and 10, v[0] = 1, v[1] = 5, v[2] = 10
	int v[];
	//A is the amount of change needed to make 
	int A;
	//i is the number of denominations of coins. Both c and v should have i
	//elements when initializing the coin
	int i;
};