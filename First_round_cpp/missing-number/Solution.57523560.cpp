class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //æè·¯æ¯è¾å¥ç¹ç­å·®æ°åæ±å
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n=nums.size();
        return (n+1)*n/2-sum;
    }
};