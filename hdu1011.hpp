#pragma once 
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define max(l,m) ((l)>(m)?(l):(m))

namespace hdu1011 {

const int MAXN = 110;

struct Node
{
	Node *from;
	std::vector<Node *> to;
	int index;
	int bug;
	int brain;

	Node()
		:from(NULL), index(-1), bug(0), brain(0)
	{
	}
};

Node *nodes[MAXN+1];
int dp[MAXN+1][MAXN+1];
bool vis[MAXN+1];

void tree_dp(Node *node,const int &M)
{ 
	int cost = (node->bug + 19) / 20;

	for (int i = cost; i <= M; i++) 
		dp[node->index][i] = node->brain;

	vis[node->index] = true;

	////LEAF
	//if (node->to.size() == 0)
	//{
	//	dp[node->index][M] = node->brain;
	//}
	////NODE
	//else
	//{
		for (int i = 0; i < node->to.size(); ++i)
		{
			Node *NextNode = node->to[i];

			if (vis[NextNode->index])
				continue;

			tree_dp(NextNode, M-cost);
			
			for (int j = M; j >= cost; --j)
				for (int k = 1; j+k<=M; ++k)
					if(dp[node->index][j+k])
						dp[node->index][j+k] = max(dp[NextNode->index][j-k] + dp[node->index][k], dp[node->index][j]);
		}
	//} 
}

void run()
{
	int N, M;
	for (;scanf("%d %d",&N,&M),N!=-1&&M!=-1;)
	{
		for (int i = 1; i <= N; ++i)
		{
			nodes[i] = new Node();
			scanf("%d %d", &nodes[i]->bug, &nodes[i]->brain);
			nodes[i]->index = i;
		}

		int from, to;

		for (int i = 0; i < N-1; ++i)
		{
			scanf("%d %d", &from, &to);

			nodes[from]->to.push_back(nodes[to]);
			nodes[to]->from = nodes[from];
		}

		int root_index = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (nodes[i]->from == NULL)
			{
				root_index = i;
				break;
			}
		}

		if (N == 0 || M == 0)
		{
			printf("%d\n", 0);
		}
		else
		{
			memset(vis, false, sizeof(bool)*(MAXN + 1));
			memset(dp, 0, sizeof(int)*(MAXN + 1)*(MAXN + 1));
			tree_dp(nodes[root_index], M);
			printf("%d\n", dp[root_index][M]);
		}
	}
}

} 