[原题](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

题意：

给定的输入矩阵是排好序的，找两个数字的和是sum，返回下标。


双指针，贪心，即可。


```
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(numbers) - 1
        while l < r:
            if numbers[l] + numbers[r] == target:
                return [l+1, r+1]
            elif numbers[l] + numbers[r] < target:
                l += 1
            else:
                r -= 1
        
```
