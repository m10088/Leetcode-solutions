[原题](https://leetcode.com/problems/partition-equal-subset-sumy)

题意:

给定一组数字，判断是不是能够分出两个集合，让他们的和相等，这道题目一看难道又是dfs？如果向那道木棍的题目那么去做，肯定超时。

转化一下，也就是能否选择一些数字凑成 sum / 2，这就变成了一个dp题目，只用前i个数字能否凑出数字target来。

如果用```dp[i][j]```，发现超时了，使用了一个hash，过了。

题解:

```
cache = dict()
class Solution(object):
    def canPartition(self, nums):
        cache = dict()
        """
        :type nums: List[int]
        :rtype: bool
        """
        if sum(nums) % 2 == 1: return False
        tar, n = sum(nums) // 2, len(nums)
        dp = set([0])
        # dp代表能够凑出的数字有哪些？
        for i in range(n):
            tmp = [x + nums[i] for x in dp]
            for item in tmp:
                dp.add(item)
        return tar in dp
```