#ifndef oj_hdu1018_hpp
#define oj_hdu1018_hpp

#include <stdio.h>
#include <math.h>
#include <string.h>

int cFactorial(int n)
{
    double log10_sum = 0;
    
    for(int i=1;i<=n;++i)
    {
        log10_sum += log10((double)i);
    }
    
    int ret = (int)log10_sum;
    
    return log10_sum>ret?ret+1:ret;
}

void run()
{
    int nCase;
    
    for(;~scanf("%d",&nCase);)
    {
        int n;
        for(int i=0;i<nCase;++i)
        {
            scanf("%d",&n);
            printf("%d\n",cFactorial(n));
        }
    }
}

#endif
