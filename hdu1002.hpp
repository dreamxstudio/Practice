#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
namespace hdu1002 {

	const static int MAXN = 1005;

	void run()
	{
		char a[MAXN], b[MAXN], c[MAXN];
		int t;
		for (; ~scanf("%d", &t);)
		{
			for (int index = 0; index < t; ++index)
			{
				memset(c, 0, sizeof(char)*MAXN);

				scanf("%s %s", a, b);

				int len_a = strlen(a);
				int len_b = strlen(b);

				int trailing_pos_a = -1;
				int trailing_pos_b = -1;

				for (int i = 0; i < len_a; ++i)
				{
					if (a[i] == '0'&&i < len_a - 1)
						trailing_pos_a = i;
					else
						break;
				}

				for (int i = 0; i < len_b; ++i)
				{
					if (b[i] == '0'&&i < len_b - 1)
						trailing_pos_b = i;
					else
						break;
				}

				int min_len = len_a < len_b ? len_a : len_b;
				int max_len = len_a > len_b ? len_a : len_b;

				int grade = 0;

				int idx_c = 0;
				int idx_a = len_a - 1;
				int idx_b = len_b - 1;

				for (int i = min_len - 1; i >= 0; --i)
				{
					if (i <= trailing_pos_a && i <= trailing_pos_b)
						break;

					char c_a = a[idx_a];
					char c_b = b[idx_b];

					int value = (i <= trailing_pos_a ? 0 : c_a - '0') + (i <= trailing_pos_b ? 0 : c_b - '0') + grade;
					grade = value / 10;
					c[idx_c++] = value % 10 + '0';

					--idx_a;
					--idx_b;
				}

				for (; idx_a >= 0;)
				{
					if (idx_a <= trailing_pos_a  && grade == 0)
						break;

					char c_a = a[idx_a];

					int value = (idx_a <= trailing_pos_a ? 0 : c_a - '0') + grade;

					grade = value / 10;
					c[idx_c++] = value % 10 + '0';

					--idx_a;
				}

				for (; idx_b >= 0;)
				{
					if (idx_b <= trailing_pos_b && grade == 0)
						break;

					char c_b = b[idx_b];

					int value = (idx_b <= trailing_pos_b ? 0 : c_b - '0') + grade;
					grade = value / 10;
					c[idx_c++] = value % 10 + '0';

					--idx_b;
				}

				for (; grade != 0;)
				{
					c[idx_c++] = grade % 10 + '0';
					grade /= 10;
				}

				printf("Case %d:\n%s + %s = ", index + 1, a, b);
				for (int i = idx_c - 1; i >= 0; --i)
					putchar(c[i]);
				puts("");
				if (index != t - 1)
					puts("");
			}
		}
	}
}