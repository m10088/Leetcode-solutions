[原题](https://leetcode.com/problems/ones-and-zeroes)

题意:

最多消耗m个0，和n个1，最多能获得字符串数组中的几个字符串。

题解:

背包问题的变形，不过是代价是一个二维的，收获是一个数量。

```
class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        cache = dict()
        # 其实就是典型的背包问题
        # dp[i][m][n] = max(dp[i-1][m][n], dp[i-1][m-NUM_M][n-NUM_N])
        # 为了提高空间效率，使用滚动数组，不过要从后面进行更新
        tmp = [0] * (m+1)
        dp = [tmp[:] for i in range(n+1)] # dp第一位是n，第二维是m
        for s in strs:
            ones, zeros = s.count('1'), s.count('0')
            for i in range(n, ones-1 , -1):
                for j in range(m, zeros-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-ones][j-zeros] + 1)
        return dp[n][m]
        
```
