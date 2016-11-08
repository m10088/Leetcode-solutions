[原题](https://leetcode.com/problems/minimum-path-sum/)

题意：

一个方格，从最左下角，到最右下角，路径的最短是多少。

dp即可。但是这里可是使用滚动数组，优化空间复杂度。


```
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) == 0: return 0
        n, m = len(grid), len(grid[0])
        dp = [[0] * m] * n
        for i in range(0, n):
            for j in range(0, m):
                if i == 0 and j == 0:
                    dp[0][0] = grid[0][0]
                elif i == 0 and j != 0:
                    dp[0][j] = dp[0][j-1] + grid[0][j]
                elif i != 0 and j == 0:
                    dp[i][0] = dp[i-1][0] + grid[i][0]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        return dp[n-1][m-1]
        
                    
```

滚动数组。

```
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        INF = 0x7fffffff
        if not len(grid):
            return 0
        width = len(grid[0]) + 1
        dp = [INF for _ in xrange(width)]

        for row in xrange(len(grid)):
            dp[0] = 0 if not row else INF
            for col in xrange(1, width):
                dp[col] = min(dp[col], dp[col - 1]) + grid[row][col - 1]

        return dp[width - 1]
```

