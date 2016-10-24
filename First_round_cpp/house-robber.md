```c++
#define N 1007
int dp[N][2];
class Solution {
public:
    int rob(vector<int>& a) {
        memset(dp,0,sizeof(dp));
        int n=a.size();
        if(n==0)return 0;
        if(n==1)return a[0];
        
        dp[0][0]=0;
        dp[0][1]=a[0];
        for(int i=1;i<n;i++){
           dp[i][1]=dp[i-1][0]+a[i];
           dp[i][0]=std::max(dp[i-1][0],dp[i-1][1]);
        }
        return std::max(dp[n-1][0],dp[n-1][1]);
    }
}
```
