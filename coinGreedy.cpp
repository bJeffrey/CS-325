#include "coinGreedy.h"

void coinGreedy(int *c, int *v, int i, int A)
{
	while (A > 0)
	{
		if (A >= v[i])
		{
			A =- v[i];
			x.c[i]++;
		}
		else if(i > 0)
		{
			i--;
		}
		else
		{
			A =- v[i];
			c[i]++;
		}
	}
}
