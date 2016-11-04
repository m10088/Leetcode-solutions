```c++
class Solution {
    public:

        void sortColors(vector<int>& nums) {
            int zero = 0, one = 0, two = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0)zero++;
                if (nums[i] == 1)one++;
                if (nums[i] == 2)two++;
            }
            int begin = 0;
            for (begin = 0; begin < zero; begin++) {
                nums[begin] = 0;
            }
            for (; begin < (zero + one); begin++) {
                nums[begin] = 1;
            }
            for (; begin < (nums.size()); begin++) {
                nums[begin] = 2;
            }
        }
}
```
