[原题](https://leetcode.com/problems/move-zeroes/)

题意：

给定一个数组，将数组中的零移动到最后，用最少的操作次数。


统计这个数字是第几个非零数字，然后和应该在的位置交换即可。



```
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        counter = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[counter] = nums[counter], nums[i]
                counter += 1
        
```

或者

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
```
