#ifndef UTIL_HPP
#define UTIL_HPP

#ifdef __cplusplus

#define BEGIN(l) class l{ public:
#define END };
#define RUN(l)(l) l instance; instance.run(); 

#else

#define BEGIN(l)
#define END
#define RUN(l)(l) run()
#define TEST(l) test()

#endif

struct Point2Di
{
	int x;
	int y;
};

#endif