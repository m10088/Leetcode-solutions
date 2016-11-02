[原题](https://leetcode.com/problems/third-maximum-number/)

题意：

找第三大的元素，给定的元素是不相同的：

O(n)，遍历根据情况，更新三个值。

```
class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = list(set(nums))
        if len(nums) < 3:
            return sorted(nums)[-1]
        tmp = nums[0:3]
        tmp = sorted(tmp,  reverse=True)
        fir, sec, thi = tmp
        for i in range(3, len(nums)):
            e = nums[i]
            if e > fir:
                fir, sec, thi = e, fir, sec
            elif sec < e < fir:
                fir, sec, thi = fir, e, sec
            elif thi < e < sec:
                fir, sec, thi = fir, sec, e
            else:
                pass
        return thi
```
