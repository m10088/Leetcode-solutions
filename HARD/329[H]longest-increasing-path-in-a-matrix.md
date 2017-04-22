[原题](https://leetcode.com/problems/longest-increasing-path-in-a-matrix)

题意

题解

```Python
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not matrix: return 0
        n, m = len(matrix), len(matrix[0])
        dp = [[-1] * (m+1) for i in range(n+1)]
        direc = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        def dfs(i, j):
            if dp[i][j] != -1: return dp[i][j]
            dp[i][j] = 1
            for dr in direc:
                nx, ny = i+dr[0], j+dr[1]
                if 0<=nx<n and 0<=ny<m and matrix[nx][ny] < matrix[i][j]:
                    dp[i][j] = max(dfs(nx, ny)+1, dp[i][j])
            return dp[i][j]
        ret = 0
        for i in range(n):
            for j in range(m):
                ret = max(ret, dfs(i, j))
        return ret
        
```