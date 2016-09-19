#include<algorithm>
int d[1000];
int f(vector<int>&v,int n)//index_n
{
    if(d[n]!=-1)return d[n];
    else
    {
        if(n==0)
            return d[0]=v[0];
        if(n==1)
            return d[1]=v[1];
        else
        {
            int maxer=*std::max_element(d+0,d+n-1);
            return d[n]=maxer+v[n];
        }
    }
}

class Solution {
public:
    int rob(vector<int>& nums) {
        for(auto i=0;i<1000;i++)
        {
            d[i]=-1;
        }
        for(int i=0;i<nums.size();i++)
        {
            f(nums,i);
        }
        
        for(auto x=0;x<4;x++)std::cout<<d[x]<<std::endl; 
        
        if(*std::max_element(d+0,d+999)==-1)
            return 0;
        else
            return *std::max_element(d+0,d+999);
        
    }
};