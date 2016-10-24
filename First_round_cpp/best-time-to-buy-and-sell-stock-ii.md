```c++
class Solution {
public:
    int maxProfit(vector<int>& v) {
        if(v.size()<=1)return 0;
        int p=0;
        int q=1;
        int sum=0;
        while(1)
        {
            if(v[q]>v[p])
            {sum=sum+v[q]-v[p];}
            p++;
            if(p==v.size()-1)
            {break;}
            q++;
            
         
        }
        return sum;
    }
}
```
