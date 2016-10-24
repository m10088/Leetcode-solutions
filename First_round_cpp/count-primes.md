```c++
bool d[10000000];
class Solution {
public:
    int countPrimes(int n){
        
        if(n<=2)return 0;
        int cnt=0;
        d[0]=d[1]=1;
        for(int i=1;i<n;i++)
        {
            if(d[i]==0)
            {
                cnt++;
                for(int k=2;k<n/i+1;k++)
                {
                    d[k*i]=1;
                }
            }
        }
        return cnt;
        
        }
    
}
```
