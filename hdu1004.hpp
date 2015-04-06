#ifndef HDU1004_HPP
#define	HDU1004_HPP

/* 
 * File:   hde1004.hpp
 * Author: shijie
 * Desc:  try to declare variables on heap instead of stack for writing clean code.
 * Created on 2015/4/6
 */

#ifdef __cplusplus

#include <map>
#include <string>
#include <iostream>

#define PROC_BEGIN(l) class l{ public:
#define PROC_END };
#define RUN_STACK(l) l instance; instance.run_stack();
#define RUN_HEAP(l) l instance; instance.run_heap();
#define RUN(l) l instance; instance.run();

#else

#define PROC_BEGIN(l)
#define PROC_END
#define RUN_STACK(l) run_stack()
#define RUN_HEAP(l) run_heap()
#define RUN(l) run()

#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

PROC_BEGIN(hdu1004)
   
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

PROC_END

#ifdef OJ

/*
 * MAINAPP
 */
int main(int argc, char** argv) 
{
    RUN(hdu1004);
    return 0;
}

#endif


#endif	/* HDU1004_HPP */

