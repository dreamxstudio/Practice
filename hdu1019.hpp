#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int GCD(int a, int b)
{
	if (a < b)
		a ^= b ^= a ^= b;

	if (a == 1 || b == 1)
		return 1;

	if (a != b)
	{ 
		int c = std::max(b, a - b);
		int d = std::min(b, a - b);
		return GCD(c, d);
	}

	return a;
}

int LCM( int a,  int b)
{
	int gcd = GCD(a, b);
	return (a / gcd)*b;
}

void run()
{
	int t;
	int n;
	int v;

	for (; ~scanf("%d", &t);)
	{
		for (int i = 0; i < t; ++i)
		{
			scanf("%d", &n);
			int lcm = 0;
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &v);
				if (lcm == 0)
				{
					lcm = v;
				}
				else
				{
					lcm = LCM(lcm, v);
				}
			}

			printf("%d\n", lcm);
		}
	}
}