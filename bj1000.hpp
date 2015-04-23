#include <stdio.h>

namespace BJ1000
{
	int run()
	{
		int a, b;
		for (; ~scanf("%d%d", &a, &b);)
		{
			printf("%d\n", a + b);
		}

		return 0;
	}
}

