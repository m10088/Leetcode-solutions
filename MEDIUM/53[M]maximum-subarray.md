[原题](https://leetcode.com/problems/maximum-subarray/)

题意：

最大的子数组。


可以使用dp方法。

```

dp[i] means the maximum subarray ending with A[i];

maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]; 

```

但是这里有一种巧妙的方法，就是记录前缀和，然后使用best_time_buy_stock的方式即可。

```
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 
        if not nums: return 0
        if len(nums) == 1: return nums[0]
        n = len(nums)
        
        s = [0] * (n + 1)
        for i in range(0, n):
            s[i+1] = s[i] + nums[i]
        ret = -0x3f3f3f3f
        miner = s[0]
        for i in range(1, n + 1):
            ret = max(ret, s[i] - miner)
            miner = min(miner, s[i])
        return ret
        

```


