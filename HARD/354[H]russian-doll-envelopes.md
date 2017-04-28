[原题](https://leetcode.com/problems/russian-doll-envelopes)

题意

题解

```Python
class Solution(object):
    def maxEnvelopes(self, a):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        
        # 如果使用DAG图的方法会TLE，因此使用朴素的最长上升子序列的方法
        n = len(a)
        a.sort(key=lambda x: (x[0], x[1]))
        ret = 0
        dp = [1] * (n)
        for i in range(len(a)):
            for j in range(i):
                if a[i] > a[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            ret = max(ret, dp[i])
        return ret
        
```