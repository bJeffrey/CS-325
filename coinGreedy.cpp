#include "coin.h"
struct coin(struct coin x)
{
	//creating temporary variables for use in the function
	int i = x.i;
	int A = x.A;
	while (A > 0)
	{
		if (A >= x.v[i])
		{
			A =- x.v[i];
			x.c[i]++;
		}
		else if(i > 0)
		{
			i--;
		}
		else
		{
			A =- x.v[i];
			c[i]++;
		}
	}
	return x;
}