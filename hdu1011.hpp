#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

BEGIN(hdu1011)

void run()
{
	int N, M;
	for (;scanf("%d%d",&N,&M),N!=-1&&M!=-1;)
	{

	}
}

END

#ifndef LOCAL

int main(int argc, char **argv)
{
	RUN();
	return 0;
}

#endif