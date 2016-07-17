#include "coinGreedy.h"

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