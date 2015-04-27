#ifndef oj_hdu1016_hpp
#define oj_hdu1016_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define MAXN 100

bool matrix[MAXN][MAXN];

bool is_prime(const int &n)
{
    for(int i=2;i<n;++i)
        if(n%i==0)
            return false;
    
    return true;
}

void preprocess(int n)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(!matrix[i][j]&&is_prime(i+j))
                matrix[i][j] = matrix[j][i] = true;
}

std::vector<std::string> result;

void dfs(int s,const int &n,int flag, char* path)
{
    if(flag == (1<<n) - 1 && is_prime(s+1))
    {
        result.push_back(path);
    }
    
    for(int i=2;i<=n;++i)
    {
        if((flag & (1<<(i-1))) == 0 && matrix[s][i])
        {
            char param[1024];
            sprintf(param,"%s%c",path,char('a'+i));
            
            dfs(i,n,flag |(1<<(i-1)),param);
        }
    }
}

void run()
{
    int n;
    int nCase = 0;
    
    preprocess(MAXN-1);
    
    for(;~scanf("%d",&n);)
    {
        memset(matrix,false,sizeof(bool)*MAXN);
        result.clear();
        
        char s[2] = {char('a'+1),'\0'};
        
        dfs(1,n,1,s);
        
        sort(result.begin(),result.end());
        
        std::cout<<"Case "<<++nCase<<":"<<std::endl;
        
        for(int i=0;i<result.size();++i)
        {
            for(int j=0;j<result[i].size();++j)
            {
                if(j>0)
                    printf(" ");
               
                printf("%d",result[i][j]-'a');
            }
            puts("");
        }
        
        puts("");
    }
}


#endif
