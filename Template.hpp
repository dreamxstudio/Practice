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

BEGIN() 

void run()
{ 

}

END

#ifndef LOCAL

int main(int argc, char **argv)
{
	run();
	return 0;
}

#endif