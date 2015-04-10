

#ifndef HDU1003_HPP
#define	HDU1003_HPP

/* 
 * File:   hde1003.hpp
 * Author: shijie
 * Desc:  try to declare variables on heap instead of stack for writing clean code.
 * Created on 2015/4/6
 */

#ifdef __cplusplus

#define BEGIN(l) class l{ public:
#define END }; 
#define RUN(l) l instance; instance.run();

#else

#define PROC_BEGIN(l)
#define PROC_END 
#define RUN(l) run()

#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//O(N)
BEGIN(hdu1003)

const int MAXN = 100001;
 
void calc(int *a,int *s,const int &idx,const int &len)
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
    int nCase;
    scanf("%d",&nCase);
    
    for (int idx = 0; idx < nCase;++idx)
    {
        int nNum;
        scanf("%d",&nNum);
        
        int *a = new int[nNum];
        int *s = new int[nNum];
        
        for (int i = 0; i < nNum; ++i)
            scanf("%d",&a[i]);
        
        calc(a,s,idx,nNum);
        
        delete [] a;
        delete [] s;
    }
}

END

#ifdef LOCAL

/*
 * MAINAPP
 */
int main(int argc, char** argv) 
{
    RUN_STACK(hdu1003);
    
    return 0;
}

#endif


#endif	/* HDU1003_HPP */

