[原题](https://leetcode.com/problems/minimum-size-subarray-sum/)


题意：

给定一个全是正数的数组，并且给定一个target，找到大于等于target的最短的数组的长度。



双指针，注意退出循环的情况即可。


```
class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        # Two pointers
        if not nums: return 0
        n = len(nums)
        l, r, s, ret = 0, 0, nums[0], 0x3f3f3f3f
        while l <= r:
            if s >= target:
                ret = min(r-l+1, ret)
                s = s - nums[l]
                l = l + 1
            else:
                r = r + 1
                if r >= n:
                    break
                s = s + nums[r]
        return 0 if ret == 0x3f3f3f3f else ret
```