```c++

long long c(long long x,long long y)
{
    if(y==0)return 1;
    if(y*2>x)
    return c(x,x-y);
    else
    {
        long long res=1;
        long long t=x-y+1;
        long long s=1;
        for(auto i=1;i<=y;i++)
        {
            res=t*res/s;
            t++;
            s++;
        }
        return res;
    }
}
class Solution {
public:
    vector<int> getRow(long long r) {
        vector<int> res;
        for(auto x=0;x<=r;x++)
        res.push_back(c(r,x));
        return res;
    }
}
```
