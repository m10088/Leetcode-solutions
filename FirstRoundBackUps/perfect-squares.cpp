int d[100000];
int fmax(int x)
{
    int n=1;
    while(1)
    {
        if(n*n>x)
            return (n-1);
        n++;
    }
}
int fx(int i)
{
    if(d[i]!=-1)
        return d[i];
    if(i==0)return d[i]=0;
    else
    {
            int m=fmax(i);
            int miner=fx(i-m*m);
            for(int k=m-1;k>=1;k--)
            {
                if(fx(i-k*k)<miner)
                    miner=fx(i-k*k);
            }
            
            return d[i]=miner+1;
    }
}
class Solution {
public:
    int numSquares(int n) {
        for(auto i=0;i<100000;i++)
        {
            d[i]=-1;
        }
        return fx(n);
    }
};