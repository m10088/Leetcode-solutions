[原题](https://leetcode.com/problems/wiggle-sort-ii)

题意:

给定一个数组，按照下面的性质，重新排列整个数组。

```
nums[0] < nums[1] > nums[2] < nums[3]
```


题解:

code tells everything.

```
class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        half = len(nums[::2])
        nums[::2], nums[1::2] = nums[:half][::-1], nums[half:][::-1]
        print nums
        # 正确的方式
        # 1,2,3,4,5,6 => 3,6,2,5,1,4
        # 1,2,3,4,5 => 3,5,2,4,1
        
        # 如果按照折叠的方式，那么中间的两个元素可能是相同的
        # 1,2,3,4,5,6 => 1,6,2,5,3,4
        # 1,1,2,2,3,3 => 1,3,1,3,2,2
        
        # 这种方式是错误的
        
```