#ifndef HDU1004_HPP
#define	HDU1004_HPP
 
#include <map>
#include <string>
#include <iostream>

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
#define RUN(l) run()
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

BEGIN(hdu1004)
   
void run()
{ 
    int n;
    
    for(;scanf("%d",&n),n;)
    {
        std::map<std::string,int> __dic;
        int max_n=INT_MIN;
        std::string max_color = "";
        std::string color = "";
    
        for(int i=0;i<n;++i)
        {
            std::cin>>color;
            __dic[color]++;
            if(max_n < __dic[color])
            {
                max_n = __dic[color];
                max_color = color;
            }
        }
        
        std::cout<<max_color<<std::endl;
    }
}

END 

#ifndef LOCAL

int main(int argc, char **argv)
{
	run();
	return 0;
}

#endif

#endif	/* HDU1004_HPP */

