```c++
#include<cmath>
int get(int x)
{
    int res=0;
    for(auto i=1;i<x;i++)
    {res+=pow(26,i);}
    return res;
}
int num(char c)
{
    return c-65;
}
class Solution {
public:
    int titleToNumber(string s) {
        int sz=s.size();
        int base=get(sz);
        for(int k=sz-1;k>=0;k--)
        {
            base+=num(s[sz-(k+1)])*pow(26,k);
        }
        return base+1;
       
    }
}
```
