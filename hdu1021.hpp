#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000001

int FIB[MAXN];

void init()
{
	FIB[0] = 7;
	FIB[1] = 11;
	for (int i = 2; i < MAXN; ++i)
	{
		FIB[i] = (FIB[i - 1] % 3 + FIB[i - 2] % 3) % 3;
	}
}

void run()
{
	init();

	int n;
	for (;~scanf("%d",&n);)
	{
		if (FIB[n] % 3 == 0)
			puts("yes");
		else
			puts("no");
	}
}