#ifndef HDU1005_HPP
#define	HDU1005_HPP

#ifdef __cplusplus

#define BEGIN(l) class l{ public:
#define END };
#define RUN(l) l instance; instance.run();
#define TEST(l) l instance; instance.test();

#else

#define BEGIN(l)
#define END
#define RUN(l) run()
#define TEST(l) test()

#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

BEGIN(hdu1005)

#define MAXN 7

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

#ifdef OJ

int main(int argc, char** argv) 
{
    RUN(hdu1005);
    
    return 0;
}

#endif

#endif	/* HDU1005_HPP */
