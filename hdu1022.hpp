#ifndef hdu1022_h
#define hdu1022_h

#include <stack>
#include <iostream>
#include <string>
#include <vector>

void proc(const int &n,const std::string &in_str,const std::string &out_str)
{
    int index_in = 0;
    int index_out = 0;
    
    std::vector<std::string> ops;
    
    std::stack<char> in;
    
    for(index_in=0;index_in<n;++index_in)
    {
        in.push(in_str[index_in]);
        
        ops.push_back("in");
        
        while(!in.empty()&&index_out<out_str.size()&&in.top() == out_str[index_out])
        {
            ops.push_back("out");
            in.pop();
            index_out++;
        }
    }
    
    if(in.empty())
    {
        std::cout<<"Yes."<<std::endl;
        for(int i=0;i<ops.size();++i)
            std::cout<<ops[i]<<std::endl;
    }
    else
    {
        std::cout<<"No."<<std::endl;
    }
    
    std::cout<<"FINISH"<<std::endl;
}

void run()
{
    int n;
    
    std::string in_str;
    std::string out_str;
    
    while(std::cin>>n>>in_str>>out_str)
    {
        proc(n,in_str,out_str);
    }
}

#endif
