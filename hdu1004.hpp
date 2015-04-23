#pragma once

#include <map>
#include <string>
#include <iostream>
 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

namespace hdu1004{
   
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

}  