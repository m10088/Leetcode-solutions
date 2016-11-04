```c++
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            
            int step = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (step == 0) {
                    return false;
                }
                else
                {
                    step--;
                    step = max(step, nums[i]);
                }
            }
            return true;
        }
}
```
