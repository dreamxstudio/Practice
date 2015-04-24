#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100001

int s[MAXN];
int a[MAXN];
int nCase;
int nNum;

//O(N)

void calc(const int &idx,const int &len)
{
    int max_sum = INT_MIN;
    
    int s_idx = 0;
    int e_idx = 0;
    
    
    int jump_idx = 0;
    
    for (int i = 0; i < len; ++i)
    {
        if (i == 0)
        {
            s[i] = a[i];
            s_idx = 0;
        }
        else
        {
            if(s[i-1] < 0)
            {
                s[i] = a[i];
                jump_idx = i;
            }
            else
            {
                s[i] = a[i] + s[i-1];
            }
        }
        
        if (max_sum < s[i])
        {
            if(jump_idx <= i )
            {
                s_idx = jump_idx;
            }
            e_idx = i;
            max_sum = s[i];
        }
    }
    
    if(idx>0)
        printf("\n");
    
    printf("Case %d:\n%d %d %d\n",idx+1,max_sum,s_idx+1,e_idx+1);
}

void run()
{
    scanf("%d",&nCase);
    
    for (int idx = 0; idx < nCase;++idx)
    {
        scanf("%d",&nNum);
        
        for(int i=0;i<nNum;++i)
            scanf("%d",&a[i]);
        
        calc(idx,nNum);
    }
}