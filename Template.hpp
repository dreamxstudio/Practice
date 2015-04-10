#ifndef HDU1006_HPP
#define	HDU1006_HPP

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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

BEGIN(hdu1006)



END

#ifdef OJ

int main(int argc, char** argv)
{
	RUN(hdu1006);

	return 0;
}

#endif

#endif	/* HDU1006_HPP */
