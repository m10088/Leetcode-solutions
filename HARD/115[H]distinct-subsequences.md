[原题](https://leetcode.com/problems/distinct-subsequences)

题意

题解

```Python
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        # 经过尝试发现，不能使用递归因为层数过多直接爆栈，因此使用迭代实现更有效率
        
        n, m = len(s), len(t)
        if n < m: return 0
        dp = [[0] * (m+1) for i in range(n+1)]
        for i in range(n+1):
            dp[i][0] = 1
        
        for i in range(1, n+1):
            for j in range(1, m+1):
                if s[i-1]==t[j-1]:
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        #print dp
        return dp[n][m]
        
        
```