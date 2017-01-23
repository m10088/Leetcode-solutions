[原题](https://leetcode.com/problems/maximal-square)

题意:


给定一个二维的数组，只有0和1组成，求最大的正方形是多大。




题解:


首先我的想法大致上是正确的，就是```dp[i][j]```存放的是从开头到i，j位置的最大的正方形。

最大的问题就是如何根据```dp[i-1][j]```, ```dp[i][j-1]```，```dp[i-1][j-1]```这三个状态更新，出本个位置的值。

刚开始采用的是判断如果左边和上边都是1的话，那么```dp[i][j] = dp[i][j] + 1```。
很明显是错误的。

但是有趣的是，下面这种判断方法，很简单的就ac了，具体的证明，画个图就行了。


```
dp[i][j] = min([dp[i-1][j], dp[i][j-1], dp[i-1][j-1]]) + 1
```

源码。

```Python
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        n = len(matrix)
        if not n: return 0
        m = len(matrix[0])
        
        tmp = [0] * m
        dp = [tmp[:] for i in range(n)]
        mmax = 0
        # 初始化第一行和第一列
        for i in range(m): 
            if matrix[0][i] == '1': dp[0][i], mmax = 1, 1
        for i in range(n):
            if matrix[i][0] == '1': dp[i][0], mmax = 1, 1
        
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == '0':
                    dp[i][j] = 0
                    continue
                else:
                    dp[i][j] = min([dp[i-1][j], dp[i][j-1], dp[i-1][j-1]]) + 1
                    # this is interesting, need drawing to prove :)
                mmax = max(mmax, dp[i][j])
        
        return mmax**2
```
