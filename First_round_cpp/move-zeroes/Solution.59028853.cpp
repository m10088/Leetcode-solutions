class Solution {
public:
   void moveZeroes(vector<int>& nums) {
        for (int index = 0, current = 0; current < nums.size(); current++) {
            if (nums[current] != 0)
                swap(nums[index++], nums[current]);
        }
    }
};