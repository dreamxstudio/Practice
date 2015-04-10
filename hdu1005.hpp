#ifndef HDU1005_HPP
#define	HDU1005_HPP

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

BEGIN(hdu1005)

const static int MAXN = 7;

int cycle[MAXN*MAXN+1];
 
int detect_cycle_len(const int &a,const int &b)
{
    cycle[1] = 1;
    cycle[2] = 1;
    
    for(int i=3;i<=MAXN*MAXN;++i)
    {
        cycle[i] = (a*cycle[i-1]+b*cycle[i-2])%7;
    }
    
    int i = 1;
    int cycle_len = MAXN*MAXN;
    for(int j = i+1;j<=MAXN*MAXN;++j)
    {
        if(cycle[i] == cycle[j])
        {
            cycle_len = j-i;
            
            bool matched = true;
           
            int index1 = i+1;
            int index2 = j+1; 
            while(index2<=MAXN*MAXN && matched)
            {
                if(cycle[index1] != cycle[index2])
                {
                    matched = false;
                    break;
                }
                
                ++index1;
                ++index2;
            } 
            
            if(matched)
            {
                return cycle_len;
            }
        }
    }  
    
    return MAXN*MAXN;
}

void run()
{ 
    int a,b,n;
    
    for(;scanf("%d%d%d",&a,&b,&n),a||b||n;)
    {
        int cyclelen = detect_cycle_len(a,b);
        
        n = n%cyclelen;
        if(n == 0)
            n = cyclelen;
        printf("%d\n",cycle[n]);
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

#endif	/* HDU1005_HPP */
