[原题](https://leetcode.com/problems/missing-number/)


题意：

0-n之间丢了一个数字，找到这个数字是什么。

等差数列求和 - sum即可。


```
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        s = n * (n + 1) // 2
        return s - sum(nums)
        
        
```