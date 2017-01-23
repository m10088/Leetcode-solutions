[原题](https://leetcode.com/problems/number-of-islands/)

题意：

dfs求联通岛的数目。

```Python
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        n = len(grid)
        if not n: return 0
        m = len(grid[0])
        direction = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        def dfs(i, j):
            if not (0<=i<n and 0<=j<m): return
            # indacating that we have visited this grid already
            if grid[i][j] != '1': return
            grid[i][j] = '0'
            for d in direction:
                dfs(i+d[0], j+d[1])
            
        cnt = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    cnt += 1
                    dfs(i, j)
        return cnt
                
            
        
```