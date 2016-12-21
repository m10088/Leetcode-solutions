#define INF 0xfffffff
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int * dp=new int[nums.size()+7];
        for(int i=0;i<nums.size()+7;i++){dp[i]=INF;}
        for(int i=0;i<nums.size();i++){
            *lower_bound(dp,dp+nums.size()+7,nums[i])=nums[i];
        }
        return lower_bound(dp,dp+nums.size()+7,INF)-dp;
    }
};