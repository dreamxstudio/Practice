#ifndef oj_hdu1017_hpp
#define oj_hdu1017_hpp

#include <stdio.h>
#include <stdlib.h>

int calc(int n,int m)
{
    int cnt = 0;
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<i;++j)
        {
            if((i*i+j*j+m)%(i*j)==0)
            {
                ++cnt;
            }
        }
    }
    
    return cnt;
}

void run()
{
    int nCase;
    int n,m;
    
    scanf("%d",&nCase);
    
    for(int i=0;i<nCase;++i)
    {
        int idx = 0;
        
        for(;scanf("%d%d",&n,&m),n+m;)
        {
            printf("Case %d: %d\n",++idx,calc(n,m));
        }
        
        if(i!=nCase-1)
            printf("\n");
    }
}

#endif
