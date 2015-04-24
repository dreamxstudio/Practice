#ifndef oj_hdu1015_hpp
#define oj_hdu1015_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

static int V1[27];
static int W2[27];
static int X3[27];
static int Y4[27];
static int Z5[27];

int pow_i(int n,int e)
{
    int ret_v = 1;
    
    for(int i=0;i<e;++i)
        ret_v*=n;
    
    return ret_v;
}

void init()
{
    for(int i=0;i<26;++i)
    {
        V1[i] = pow_i(i+1,1);
        W2[i] = pow_i(i+1,2);
        X3[i] = pow_i(i+1,3);
        Y4[i] = pow_i(i+1,4);
        Z5[i] = pow_i(i+1,5);
    }
}

void run()
{
    int n;
    std::string str;
    
    init();
    
    for(;std::cin>>n>>str,n!=0 && str!="END";)
    {
        std::sort(str.begin(),str.end());
        
        std::string ret = "";
        
        for(int i=(int)str.size()-1;i>=0&&ret=="";--i)
        {
            for(int j=(int)str.size()-1;j>=0&&ret=="";--j)
            {
                if(i!=j)
                for(int k=(int)str.size()-1;k>=0&&ret=="";--k)
                {
                    if(k!=j&&k!=i)
                    for(int l=(int)str.size()-1;l>=0&&ret=="";--l)
                    {
                        if(l!=k&&l!=j&&l!=i)
                        for(int m=(int)str.size()-1;m>=0&&ret=="";--m)
                        {
                            if(m!=i&&m!=j&&m!=k&&m!=l&&V1[str[i]-'A']-W2[str[j]-'A']+X3[str[k]-'A']-Y4[str[l]-'A']+Z5[str[m]-'A']==n)
                            {
                                std::string newRet = "";
                                newRet+=str[i];
                                newRet+=str[j];
                                newRet+=str[k];
                                newRet+=str[l];
                                newRet+=str[m];
                                
                                if(newRet>ret)
                                    ret = newRet;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        std::cout<<(ret==""?"no solution":ret)<<std::endl;
    }
}

#endif
