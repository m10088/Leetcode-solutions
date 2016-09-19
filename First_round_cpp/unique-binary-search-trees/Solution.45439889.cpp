int d[100];
class Solution {
public:
    int numTrees(int n) {
        for(auto i=0;i!=100;i++)
        {
            d[i]=0;
        }
        d[0]=1;
        d[1]=1;
        for(auto x=2;x<=n;x++)
        {
            for(auto i=0;i<=x-1;i++)
            {
                d[x]=d[x]+d[i]*d[x-1-i];
            }
        }
        return d[n];
    }
};