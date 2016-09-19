#define N 1000
int dp[N][N];

int dfs(int i,int j,const string& s,const string &t){//
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==0&&j==0)return dp[i][j]=0;
    else if(i==0) return dp[0][j]=j;
    else if(j==0) return dp[i][0]=i;
    else{
        int first=dfs(i-1,j,s,t)+1;//èèæ·»å æèå é¤
        int second=dfs(i,j-1,s,t)+1;
        int third;
        if(s[i-1]==t[j-1]){
            third=dfs(i-1,j-1,s,t);
        }else{
            third=dfs(i-1,j-1,s,t)+1;
        }
        return dp[i][j]=min(min(first,second),third);
    }
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        if(word2.size()==0&&word1.size()==0)return 0;
        
        return dfs(word1.size(),word2.size(),word1,word2);
    }
};