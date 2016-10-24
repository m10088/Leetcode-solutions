```c++
#define N 1007
#define INF 0x3f3f3f3f
int dp[N][N];
int m,n;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool islegal(int i,int j){
    if(i==-1||i==n||j==-1||j==m)return false;
    else return true;
}

int dfs(int i,int j,const vector<vector<int>>& v){
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int maxer=1;
    for(int k=0;k<4;k++){
        if( islegal(i+dx[k],j+dy[k]) && v[i+dx[k]][j+dy[k]]>v[i][j])
            maxer=std::max(dfs(i+dx[k],j+dy[k],v)+1,maxer);
    }
    return dp[i][j]=maxer;
}
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& v) {
        if(v.size()==0)return 0;
        memset(dp,-1,sizeof(dp));
        n=v.size(),m=v[0].size();
        int maxer=-INF;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxer=std::max(maxer,dfs(i,j,v));
            }
        }
        return maxer;
    }
}
```
