[原题](https://leetcode.com/problems/total-hamming-distance)

题意:

给定一个数组，求数组中任意两个数字之间的海明码的距离，求这些距离的和。

题解:

当然暴力肯定是会超时的。

一个数组记录，从0-31位，每个位置上1的有多少个，那么0的个数就是n-数字1的个数。

然后对于每个位置，0的个数 * 1的个数，就能得出当前位，为最后的结果贡献了多少。

```Python
class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res, n = 0, len(nums) 
        # 一个数组记录，从0-31位，每个位置上1的有多少个
        dp = [0] * 32
        for num in nums:
            for k in range(32):
                if num & (1 << k):
                    dp[k] += 1
        for k in range(32):
            res += dp[k] * (n-dp[k])
        return res
```