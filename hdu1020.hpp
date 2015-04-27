#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>

std::string shrink_str(std::string str)
{
	std::string ret = "";
	int cursor = -1;
	for (int i = 0; i < str.size(); ++i)
	{
		if (i == 0)
			cursor = i;
		else
		{
			if (str[i] != str[cursor])
			{
				char d[1024];
				sprintf(d, "%d", i - cursor);
				
				if ( i - cursor > 1 )
					ret += d;
				ret += str[cursor];

				cursor = i;

				if (i == str.size() - 1)
				{
					ret += str[i];
				}
			} 
			else if (i == str.size() - 1)
			{
				char d[1024];
				sprintf(d, "%d", i - cursor+1);
				
				if (i - cursor > 1)
					ret += d;

				ret += str[cursor];  
			}
		}
	}

	return ret;
}

void run()
{
	int n;
	std::string line;
	for (; ~scanf("%d", &n);)
	{
		std::cin >> line;
		std::cout<<shrink_str(line)<<std::endl;
	}
}
