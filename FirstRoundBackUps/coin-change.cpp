#define INF 0x3f3f3f3f
class Solution {
public:
    int coinChange(vector<int>& c, int W) {
        if(c.size()==0)return -1;
        if(W==0)return 0;
        int size=W+7;
        int *dp=new int [size];
        for(int i=0;i<size;i++){dp[i]=INF;}
        
        for(int i=0;i<=W;i++){
            if(i%c[0]==0){
                dp[i]=i/c[0];
            }
        }
        for(int i=1;i<c.size();i++){
            for(int j=0;j<=W;j++){
                if(j>=c[i]){
                    dp[j]=std::min(dp[j-c[i]]+1,dp[j]);
                    
                }
            }
        }
        if(dp[W]==INF)return  -1;
        return dp[W];
    }
};