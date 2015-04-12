#ifndef HDU1007_HPP
#define HDU1007_HPP

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

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

BEGIN(hdu1007)

struct st_point
{
	double x;
	double y;

	st_point()
	{}

	st_point(double _x, double _y) :
		x(_x), y(_y)
	{}
};

static bool cmpx(const st_point &a, const st_point &b)
{
	if (a.x != b.x)
		return a.x<b.x;
	return a.y<b.y;
}

static bool cmpy(const st_point &a, const st_point &b)
{
	if (a.y != b.y)
		return a.y<b.y;
	return a.x<b.x;
}

double dist(const st_point &s, const st_point &e)
{
	return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y));
}

double nearest_pair(st_point *pts, const int &left, const int &right)
{
	if (left == right)
		return INT_MAX;

	if (left + 1 == right)
		return dist(pts[left], pts[right]);

	if (left + 2 == right)
	{
		double d1 = dist(pts[left], pts[left + 1]);
		double d2 = dist(pts[left], pts[left + 2]);
		double d3 = dist(pts[left + 1], pts[left + 2]);

		return min(d1, min(d2, d3));
	}

	int mid = (left + right) >> 1;

	double d_l = nearest_pair(pts, left, mid);
	double d_r = nearest_pair(pts, mid + 1, right);

	double d = min(d_l, d_r);

	st_point *tmp_pts = new st_point[right - left + 1];
	int cnt = 0;
	for (int i = mid - 1; i >= left && abs(pts[mid].y - pts[i].y) < d; --i)// left; i <= right &&; ++i)
	{
		tmp_pts[cnt++] = pts[i];
	}

	for (int i = mid + 1; i <= right && abs(pts[mid].y - pts[i].y) < d; ++i)// left; i <= right &&; ++i)
	{
		tmp_pts[cnt++] = pts[i];
	}

	std::sort(tmp_pts, tmp_pts + cnt, cmpx);

	for (int i = 0; i < cnt; ++i)
	{
		for (int j = i + 1; j < cnt; ++j)
		{
			if (i != j && abs(tmp_pts[i].x - tmp_pts[j].x) < d)
			{
				double dis = dist(tmp_pts[i], tmp_pts[j]);
				if (dis < d)
				{
					d = dis;
				}
			}
		}
	}

	delete[] tmp_pts;

	return d;
}

void run()
{
	int n;
	for (; scanf("%d", &n), n;)
	{
		st_point *pts = new st_point[n];
		 
		for (int i = 0; i<n; ++i)
		{
			scanf("%lf %lf", &pts[i].x, &pts[i].y);
		}

		std::sort(pts, pts + n, cmpy);

		printf("%.2lf\n", nearest_pair(pts, 0, n - 1) / 2.0);

		delete[] pts;
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