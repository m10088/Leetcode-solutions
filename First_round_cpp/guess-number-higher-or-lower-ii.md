```c++
#define INF 0x3f3f3f3f
#define N 1005
int dp[N][N];


int dfs(int i, int j) { 
    if (dp[i][j]!=-1) return dp[i][j];
    else if (i==j) return 0;
    else if (i+1==j) return i;
    int miner = INF;
    for (int k=i+1; k<=j-1; k++){
        miner = min(miner, max(dfs(i, k-1), dfs(k+1, j)) + k);
    }
    return dp[i][j] = miner;
}


class Solution {
public:
    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        return dfs(1, n);
    }
}
```
