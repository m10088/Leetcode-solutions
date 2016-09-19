
class Solution {
public:
    //dp[i] = sum(dp[i - nums[j]]),  (i-nums[j] > 0);
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i=1; i<=target; i++) {
            for (int j=0; j<nums.size(); j++) {
                if (nums[j] <= i){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};