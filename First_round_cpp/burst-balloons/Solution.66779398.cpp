#define N 507
int dp[N][N];
int n;
void init() {
    n = 0;
    memset(dp,-1,sizeof(dp));
}

int dfs(int i, int j, vector<int> &a) {
    if (dp[i][j] != -1) return dp[i][j];
    else if (i + 1 == j) return dp[i][j]=0;
    else if (i + 2 == j) return a[i] * a[i+1] * a[i+2];
    int miner = -1;
    for (int k=i+1; k<=j-1; k++) {
        miner = max(miner, dfs(i,k,a) + dfs(k,j,a) + a[i]*a[j]*a[k]);
    }
    return dp[i][j]=miner;
}

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        init();
        vector<int> v;
        v.push_back(1);
        for (auto &m : nums) { v.push_back(m); }
        v.push_back(1);
        n = v.size();
        
        return dfs(0,n-1,v);
    }
};