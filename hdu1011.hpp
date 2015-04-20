#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LOCAL
#ifndef BEGIN
#define BEGIN(l) namespace l{ 
#endif
#ifndef END
#define END }; 
#endif
#ifndef RUN
#define RUN(l) l::run() 
#endif
#else
#ifndef BEGIN
#define BEGIN(l)
#endif
#ifndef END
#define END
#endif
#ifndef RUN
#define RUN() run()
#endif
#endif

BEGIN(hdu1011)

const int MAXN = 100;

struct Node
{
	int from;
	int to;
	int bug;
	int brain;
};

Node nodes[MAXN+1];
int dp[MAXN+1][MAXN+1];

void tree_dp(Node root)
{

}

void run()
{
	int N, M;
	for (;scanf("%d%d",&N,&M),N!=-1&&M!=-1;)
	{
		for (int i = 0; i < N; ++i)
			scanf("%d%d", &nodes[i].bug, &nodes[i].brain);

		int from, to;

		for (int i = 0; i < M; ++i)
		{
			scanf("%d %d", &from, &to);
			nodes[from].to = to;
			nodes[to].from = from;
		}

		tree_dp(nodes[0]);
	}
}

END

#ifndef LOCAL

int main(int argc, char **argv)
{
	RUN();
	return 0;
}

#endif
