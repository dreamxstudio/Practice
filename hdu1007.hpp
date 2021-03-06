#pragma once

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define max(l,m) ((l)>(m)?(l):(m))
#define min(l,m) ((l)<(m)?(l):(m))
#define abs(l) ((l)>0?(l):-(l))

namespace hdu1007{

struct Point
{
	double x;
	double y;

	Point()
	{}

	Point(double _x, double _y) :
		x(_x), y(_y)
	{}
};

static bool cmpx(const Point &a, const Point &b)
{
	if (a.x != b.x)
		return a.x<b.x;
	return a.y<b.y;
}

static bool cmpy(const Point &a, const Point &b)
{
	if (a.y != b.y)
		return a.y<b.y;
	return a.x<b.x;
}

double dist(const Point &s, const Point &e)
{
	return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y));
}

double nearest_pair(Point *pts, const int &left, const int &right)
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

	Point *tmp_pts = new Point[right - left + 1];
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
		Point *pts = new Point[n];
		 
		for (int i = 0; i<n; ++i)
		{
			scanf("%lf %lf", &pts[i].x, &pts[i].y);
		}

		std::sort(pts, pts + n, cmpy);

		printf("%.2lf\n", nearest_pair(pts, 0, n - 1) / 2.0);

		delete[] pts;
	}
}

}  