class Solution {
public:
    int maxProfit(vector<int>& p) {
        const int k=p.size();
        if(!k)return 0;
        int d[k];
        d[k-1]=p[k-1];
        for(auto i=k-2;i>=0;i--)
        {
            if(p[i]<=d[i+1])
            d[i]=d[i+1];
            else
            {
                d[i]=p[i];
            }
        }
        int max=-99999;
        for(auto x=0;x<k;x++)
        {
            if(d[x]-p[x]>max)
            {
                max=d[x]-p[x];
            }
        }
        return max;
    }
};