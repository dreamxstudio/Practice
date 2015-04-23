#include <stdio.h>

namespace BJ1000
{
	void run()
	{
		int a, b;
		for (;~scanf("%d%d",&a,&b);)
		{
			printf("%d\n", a - b);
		}
	}
}