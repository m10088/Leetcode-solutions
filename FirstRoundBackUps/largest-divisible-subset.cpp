#define N 1003
int dp[N];

int dfs(int i, vector<int> & v) {
    if (dp[i]!=-1) return dp[i];
    dp[i] = 1;
    for (int j=i-1; j>=0; j--) {
        if (v[i] % v[j]==0) {
            dp[i] = max(dp[i], dfs(j, v) + 1);
        }
    }
    return dp[i];
}
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<int> ret;
        int n = nums.size();
        if (n==0) return ret;
        if (n==1) return vector<int>(nums);//ä¸ç¡®å®æ¯ä»ä¹
        
        sort(nums.begin(), nums.end());
        for (int i=n-1; i>=0; i--) dfs(i, nums);
        for (int i=0; i<n; i++) {
            cout << dp[i] << " ";
        }
        set<int> st;
        for (int i=0; i<n; i++) {
            if (st.find(dp[i])==st.end()) {
                ret.push_back(nums[i]);
                st.insert(dp[i]);
            }
        }
        return ret;
    }
};