[原题](https://leetcode.com/problems/triangle/)

题意：

简单的dp问题，金字塔情况的三角形，从上到下的最短路径。

为了节约空间使用一维数组，但是需要从后面往前进行更新；

两个数组滚动使用也可以。

```
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        n = len(triangle)
        if n == 0: return 0
        dp = [0] * n
        dp[0] = triangle[0][0]
        print dp
        # for each row from number 1 to number n-1
        for i in range(1, n):
            # from the opposite direction
            for j in range(i, -1, -1):
                # the tail
                if j == i: dp[j] = dp[j-1] + triangle[i][j]
                # the head
                elif j == 0: dp[j] = dp[j] + triangle[i][j]
                # others
                else: dp[j] = min(dp[j], dp[j-1]) + triangle[i][j]
            
        return min(dp)
        
```
