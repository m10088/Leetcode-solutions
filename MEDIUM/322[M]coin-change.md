[原题](https://leetcode.com/problems/coin-change)

题意:

给定一个钱币的集合，判断能不能得到一个target，最少需要多少个钱币。

如果不能就返回-1.


题解:

很明显的dp问题，```dp[i][j]```定义为，前i个物品凑出j最少需要多少个钱币。

对于i个硬币，进行i次循环。

对于每个j，考虑使用多少个i硬币。

之前做过不少这样的题目了，就是完全背包问题。

使用一个一维数组从前往后滚动即可。

```Python
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        n = len(coins)
        if not n: return -1
        dp = [float('inf')] * (amount + 1)
        # dp = [tmp[:] for i in range(n)]
        # dp[i][j] => 代表只用前i个钱币，能凑出j，需要的最小的数量
        # 可以直接使用一维的滚动数组
        dp[0] = 0
        
        for i in range(n):
            for j in range(1, amount+1):
                if j-coins[i] >= 0:
                    dp[j] = min(dp[j-coins[i]] + 1, dp[j])
        
        return dp[amount] if dp[amount] != float('inf') else -1
```