[原题](https://leetcode.com/problems/unique-paths-ii/)


题意：

类似unique_path_I，但是多了障碍物的可能。

对于每一个dp元素，如果此位置上有障碍物，那么此位置的dp就是0，否则按原来的方式计算。

```
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        n = len(obstacleGrid)
        if not n: return 0
        m = len(obstacleGrid[0])
        
        dp = [[0] * (m+1)] * (n+1)
        for i in range(1, n+1):
            for j in range(1, m+1):
                # specail case
                if i == 1 and j == 1:
                    if obstacleGrid[i-1][j-1] == 1: dp[i][j] = 0
                    else: dp[i][j] = 1
                # others
                else:
                    if obstacleGrid[i-1][j-1] == 1: dp[i][j] = 0
                    else: dp[i][j] = dp[i-1][j] + dp[i][j-1]
        #print dp
        return dp[n][m]
        
                
```