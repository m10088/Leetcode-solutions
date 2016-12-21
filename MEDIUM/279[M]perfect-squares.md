[原题](https://leetcode.com/problems/perfect-squares/)


题意：


n最少能组成多少个完全平方数字的和。

12-> 4 + 4 + 4

3

13-> 4 + 9

2

明显的dp，但是TLE了。

这是原本的代码。

```
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        sqrt = lambda x: x ** 0.5 == int(x ** 0.5)
        for i in range(1, n + 1):
            if sqrt(i): dp[i] = 1
            else: dp[i] = min([dp[x] + dp[i-x] for x in range(0, i + 1) if sqrt(x)])
        return dp[n]
        
                
```

优化。

将dp变成静态的，也就是变成类的static数据。

并且内部优化可以更加的省略。

下面是优化之后的代码。


```
class Solution(object):
    _dp = [0]
    def numSquares(self, n):
        dp = self._dp
        while len(dp) <= n:
            dp += min(dp[-i*i] for i in range(1, int(len(dp)**0.5+1))) + 1,
        return dp[n]

```

之后看到一位仁兄在discuss区开大招。

值得学习的是使用了BFS进行了求解。

[详情点击这里](https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics)

