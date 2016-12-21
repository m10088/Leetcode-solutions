#define INF 0x3f3f3f3f
#define N 1007
int dp[N][2];
class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
       if(a.size()==0)return 0;
       if(a.size()==1)return a[0];
       //åè®¾ç¬¬ä¸ä¸ªåï¼è½å¾å°çæå¤§å¼ï¼è¿ä¸ªæå¤§å¼,æ¯æåä¸ä¸ªä¸åçæåµæå¤§å¼
       memset(dp,0,sizeof(dp));
       dp[0][1]=a[0];
       dp[0][0]=-INF;
       for(int i=1;i<n;i++){
           dp[i][1]=dp[i-1][0]+a[i];
           dp[i][0]=std::max(dp[i-1][0],dp[i-1][1]);
        }
        int fir=dp[n-1][0];
        //åè®¾ç¬¬ä¸ä¸ªä¸åï¼æåä¸ä¸ªå¯ä»¥åä¹å¯ä»¥ä¸å
        memset(dp,0,sizeof(dp));
       dp[0][1]=-INF;
       dp[0][0]=0;
       for(int i=1;i<n;i++){
           dp[i][1]=dp[i-1][0]+a[i];
           dp[i][0]=std::max(dp[i-1][0],dp[i-1][1]);
        }
        int sec=std::max(dp[n-1][0],dp[n-1][1]);
        return std::max(fir,sec);
       
    }
};