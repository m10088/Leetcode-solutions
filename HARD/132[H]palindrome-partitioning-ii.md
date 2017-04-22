[原题](https://leetcode.com/problems/palindrome-partitioning-ii)

题意

题解

```Python
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        ispld = [[-1] * (n+1) for i in range(n+1)]
        def dfs(i, j):
            if ispld[i][j] != -1: return ispld[i][j]
            else:
                if i == j: 
                    ispld[i][j] = 1
                elif i+1 == j:
                    ispld[i][j] = 1 if s[i]==s[j] else 0
                else:
                    if s[i]!=s[j]: ispld[i][j] = 0
                    else: ispld[i][j] = 1 if dfs(i+1, j-1) else 0
                return ispld[i][j]
        for i in range(n):
            for j in range(i,n):
                dfs(i, j)
        
        dp = [0] * (n+1)
        # dp[i]代表的是到第i个数字最少的回文分割是多少
        dp[1] = 0
        
        for i in range(2, n+1):
            if ispld[0][i-1]:
                dp[i] = 0
            else:
                dp[i] = i - 1
                for j in range(1, i):
                    if ispld[j][i-1]:
                        dp[i] = min(dp[i], dp[j] + 1)
        #print dp
        
        return dp[n]
        
```