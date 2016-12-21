#define N 12500
#define M 100
int dp[N][M];
int dfs(const string&s,const string&t,int i,int j){
    if(dp[i][j]!=-1)return dp[i][j];
    if(i<j)return dp[i][j]=0;
    if(j==0)return dp[i][j]=1;
    if(i==0)return dp[i][j]=0;
    if(s[i-1]==t[j-1])return dp[i][j]=dfs(s,t,i-1,j-1)+dfs(s,t,i-1,j);
    else return dp[i][j]=dfs(s,t,i-1,j);
}
class Solution {
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return dfs(s,t,s.size(),t.size());
    }
};