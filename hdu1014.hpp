#ifndef oj_hdu1014_hpp
#define oj_hdu1014_hpp

#include <stdio.h>
#include <algorithm>

int gcd(int m, int n)
{
    if(m != n)
    {
        int l = std::max(m,n);
        int r = std::min(m,n);
        int d = l - r;
        
        return gcd(d,r);
    }
    
    return m;
}

void run()
{
    int step,mod;
    for(;~scanf("%d%d",&step,&mod);)
    {
        printf("%10d%10d    ",step,mod);
        if(gcd(step,mod)!=1)
        {
            printf("Bad Choice\n\n");
        }
        else
        {
            printf("Good Choice\n\n");
        }
    }
}

#endif
