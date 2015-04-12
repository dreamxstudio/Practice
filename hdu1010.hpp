#ifndef HDU1010_HPP
#define HDU1010_HPP

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
 
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

#define max(l,m) ((l)>(m)?(l):(m))
#define min(l,m) ((l)<(m)?(l):(m))
#define abs(l) ((l)>0?(l):-(l))
 
BEGIN(hdu1010)

int dir[4][2] = {{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }};

bool valid(int n, int m, int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool found;

int sx, sy,ex,ey;
int N, M, T;
char matrix[10][10];
bool vis[10][10];

void dfs(int x,int y, int step)
{
	if (found || step > T)
		return;

	int condition = (T - step) - abs(ex - x) - abs(ey - y);

	if (condition < 0 || condition % 2 == 1)
		return; 

	if (step == T)
	{
		if (matrix[x][y] == 'D')
			found = true;
		return;
	}

	if (matrix[x][y] == '.' || matrix[x][y] == 'S')
	{
		vis[x][y] = true;
     
		if (x + 1 >= 0 && x + 1<N&&y >= 0 && y<M && vis[x + 1][y] == 0)  dfs(x + 1, y, step + 1);
		if (x - 1 >= 0 && x - 1<N&&y >= 0 && y<M && vis[x - 1][y] == 0)  dfs(x - 1, y, step + 1);
		if (x >= 0 && x<N&&y + 1 >= 0 && y + 1<M && vis[x][y + 1] == 0)  dfs(x, y + 1, step + 1);
		if (x >= 0 && x<N&&y - 1 >= 0 && y - 1<M && vis[x][y - 1] == 0)  dfs(x, y - 1, step + 1);

		vis[x][y] = false;
	}
}

void run()
{
	for (; scanf("%d%d%d", &N, &M, &T);)
	{
		if (N == 0 && M == 0 && T == 0)
			break;
	  
		sx = -1;
		sy = -1; 
		ex = -1;
		ey = -1;
 
		memset(vis, false, sizeof(vis));

		for (int i = 0; i < N; ++i)
		{
			getchar(); 
			scanf("%s", matrix[i]);
		}

		int tot = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (sx == -1 && sy == -1 && matrix[i][j] == 'S')
				{
					sx = i, sy = j; 
				} 
				else if (ex == -1 && ey == -1 && matrix[i][j] == 'D')
				{
					ex = i, ey = j;
				}
				else if (matrix[i][j] == '.')
					++tot;
			} 
		} 

		found = false;

		int condition = T - abs(ex - sx) - abs(ey - sy);

		if ((condition >= 0 && condition %2 == 0))
		{
			dfs(sx, sy, 0);
		}
		 
		puts(found ? "YES" : "NO"); 
	}
}

END 

#ifndef LOCAL

int main(int argc, char **argv)
{
	run();
	return 0;
}

#endif

#endif

