#ifndef HDU1009_HPP
#define HDU1009_HPP

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

BEGIN(hdu1009)

struct st_case
{
	int J;
	int F;
};

static bool cmp(const st_case &a, const st_case &b)
{
	return a.J*1.0 / a.F > b.J*1.0 / b.F;
}

void run()
{
	int m, n;
	for (; scanf("%d%d", &m, &n), m != -1 && n != -1;)
	{
		st_case *cases = new st_case[n];

		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &cases[i].J, &cases[i].F);
		}

		std::sort(cases, cases + n, cmp);

		double tot = 0;
		int idx = 0;
		while (m > 0 && idx<n)
		{
			if (cases[idx].F <= m)
			{
				m -= cases[idx].F;
				tot += cases[idx].J;
			}
			else
			{
				double ratio = m*1.0 / cases[idx].F;
				m = 0;
				tot += ratio * cases[idx].J;
			}

			++idx;
		}

		printf("%.3lf\n", tot);
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
