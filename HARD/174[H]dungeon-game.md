[原题](https://leetcode.com/problems/dungeon-game)

题意

题解

```Python
class Solution(object):
    def calculateMinimumHP(self, a):
        """
        :type a: List[List[int]]
        :rtype: int
        """
        if not a: return 0
        n, m = len(a), len(a[0])
        dp = [[0] * (m+1) for i in range(n+1)]
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                if i == n-1 and j == m-1:
                    if a[i][j] < 0: dp[i][j] = -a[i][j]
                    else: dp[i][j] = 0
                elif i==n-1:
                    tmp = dp[i][j+1] - a[i][j]
                    dp[i][j] = tmp if tmp > 0 else 0
                elif j==m-1:
                    tmp = dp[i+1][j] - a[i][j]
                    dp[i][j] = tmp if tmp > 0 else 0
                else:
                    fir, sec = dp[i][j+1] - a[i][j], dp[i+1][j] - a[i][j]
                    f = fir if fir > 0 else 0
                    s = sec if sec > 0 else 0
                    dp[i][j] = min(f, s)
                    
        return dp[0][0] + 1
                
```