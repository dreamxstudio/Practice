
#ifndef HDU1008_HPP
#define HDU1008_HPP

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

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

#define max(l,m) ((l)>(m)?(l):(m))
#define min(l,m) ((l)<(m)?(l):(m))
#define abs(l) ((l)>0?(l):-(l))

BEGIN(hdu1008)

const static int up = 6;
const static int down = 4;
const static int stay = 5;

void run()
{
	int n;
	for (; scanf("%d", &n), n;)
	{
		long long tot = 0;
		int cur;
		int prev;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &cur);
			if (i == 0)
			{
				prev = cur;
				tot += stay + cur*up;
			}
			else
			{
				int step = abs(cur - prev);
				tot += stay + step* (prev<cur ? up : down);

				prev = cur;
			}
		}

		printf("%ld\n", tot);
	}
}

END

#endif 