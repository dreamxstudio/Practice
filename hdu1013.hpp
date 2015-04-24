#ifndef oj_hdu1013_hpp
#define oj_hdu1013_hpp

#include <stdio.h>
#include <iostream>
#include <string>

int process(int num)
{
    for(;num >= 10;)
    {
        int tmp = num;
        int iter_sum = 0;
        for(;tmp>0;)
        {
            iter_sum += tmp%10;
            tmp/=10;
        }
        num = iter_sum;
    }
    
    return num;
}

int run()
{
    std::string str;
    for(;std::cin>>str&&str!="0";)
    {
        if(str.size()>0&&str[0] =='0')
            str = str.substr(str.find_first_of("0")+1);
        int sum = 0;
        for(int i=0;i<str.size();++i)
        {
            int digit = str[i]-'0';
            sum += digit;
            if(sum>10)
                sum = process(sum);
        }
        
        std::cout<<process(sum)<<std::endl;
    }
    
    return 0;
}

#endif
