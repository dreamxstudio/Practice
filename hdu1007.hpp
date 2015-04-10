#ifndef HDU1007_HPP
#define HDU1007_HPP

#include <stdio.h>
#include <limits.h> 
#include <stdlib.h>
#include <math.h>

#ifdef __cplusplus

#define BEGIN(l) class l{ public:
#define END };
#define RUN(l) l instance; instance.run(); 

#else

#define BEGIN(l)
#define END
#define RUN(l) run()
#define TEST(l) test()

#endif
 
using namespace std;

#define max(l,m) ((l)>(m)?(l):(m))
#define min(l,m) ((l)<(m)?(l):(m))
#define abs(l) ((l)>0?(l):-(l))

BEGIN(hdu1007)
 


double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void run()
{
	int n;
	for (;scanf("%d",&n),n;)
	{
		double x, y;

		double max_x, max_y, min_x, min_y;

		for (int i=0;i<n;++i)
		{
			scanf("%lf %lf", &x, &y);
			if (i == 0)
			{
				min_x = max_x = x;
				min_y = max_y = y;
			}
			else
			{
				if (min_x > x)
					min_x = x;
				if (min_y > y)
					min_y = y;
				if (max_x < x)
					max_x = x;
				if (max_y < y)
					max_y = y;
			}
		}

		printf("%.2lf\n", dist(min_x,min_y,max_x,max_y)/2);
	}
}

END

#endif
