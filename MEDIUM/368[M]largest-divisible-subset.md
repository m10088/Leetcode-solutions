[原题](https://leetcode.com/problems/largest-divisible-subset/)


题意：

给定一些不同的数字，找出一个最大的子集，满足一个性质。

任何两个数字 大的数字%小的数字 == 0。


思路：

动态规划。

排序之后，每个数字记录一个dp值，代表，如果当前元素作为最大元素出现在结果中，那么应当有几个数字。


```Python
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # var b, ind record the value and the index of the biggest element
        
        nums = sorted(nums)
        n = len(nums)
        if not n: return []
        dp = [0] * n
        pre = [-1] * n
        # base case
        dp[0] = 1
        for i in range(1, n):
            b, ind = -1, -1
            for j in range(0, i):
                if nums[i] % nums[j] == 0 and dp[j] > b:
                    b, ind = dp[j], j
                dp[i], pre[i] = dp[ind] + 1, ind
          
        
        b, ind = -1, -1
        for i in range(n):
            if dp[i] > b:
                b, ind = dp[i], i
        
        res = []
        cur = ind
        while cur != -1:
            res.append(nums[cur])
            cur = pre[cur]
        return res[::-1]
            
    
        
            
                    
                    
```