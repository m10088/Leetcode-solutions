class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        if(a.size()==0)return 0;
        const int N=a.size()+7;
        const int M=a[0].size()+7;
        int n=a.size(),m=a[0].size();
        int dp[N][M];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    dp[i][j]=a[i][j];
                }else if(i==0){
                    dp[i][j]=dp[i][j-1]+a[i][j];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j]+a[i][j];
                }else{
                    dp[i][j]=std::min(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};