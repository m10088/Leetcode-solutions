```c++


class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        const int k=t.size();
        if(k==1)return t[0][0];
        
        int d[k];
        for(int i=0;i<k;i++)
        {d[k]=0;}
        
        for(auto i=0;i<k;i++)
        {
            d[i]=t[k-1][i];
        }
        
        for(int i=k-2;i>=0;i--)
        {
            for(auto j=0;j<=i;j++)
            {
                d[j]=min(d[j],d[j+1])+t[i][j];
            }
        }
        return d[0];
    }
}
```
