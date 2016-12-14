[原题](https://leetcode.com/problems/house-robber-ii/)

题意：

houserob升级版，也就是将首和尾部联系起来了。

这样的话，分情况遍历两次就行了。

```
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        dp = [0] * (len(nums) + 1)
        # 分为两种情况讨论，第一个rob，那么最后一个肯定不能rob
        dp[1] = nums[0]
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
        first = dp[-2] if len(nums) > 1 else dp[1] # sepecail case
        
        # 第一个不rob，那么最后一个可以rob也可以不rob
        dp = [0] * (len(nums) + 1)
        for i in range(2, len(nums)+1):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
        second = dp[-1]
        
        return max(first, second)
        
        
```