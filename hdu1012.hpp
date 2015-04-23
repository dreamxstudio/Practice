#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

namespace hdu1012{

	void run()
	{
		puts("n e\n- -----------");
		double e = 0; 
		double tmp = 0;
		for (int i = 0; i <= 9; ++i)
		{
			if (i == 0)
				tmp = 1;
			else  {
				tmp = i*tmp;
			}
			 
			e = e + 1.0/(double)tmp;
			 
			if (i == 0)
				puts("0 1");
			else if (i == 1)
				puts("1 2");
			else if (i == 2)
				puts("2 2.5");
			else 
				printf("%d %.9lf\n", i, e);
		}
	}
}