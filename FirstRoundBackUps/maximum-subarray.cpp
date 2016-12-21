#include<algorithm>
class Solution {
public:
    int maxSubArray(vector<int>& v) {
    
        const int k=v.size();
        int d[k]={-(1<<15)};
        for(int m=k-1;m>=0;m--)
        {
            if(m==k-1)
            {
                d[m]=v[m];
                
            }
            else
            {
                d[m]=max(v[m],v[m]+d[m+1]);
            }
        }
        return *std::max_element(d,d+k);
        
        
    }
};