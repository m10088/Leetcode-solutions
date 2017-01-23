[原题](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

题意：

一维数组，前后两个位置，后面的值 - 前面的值，最大是多少？

遍历的同时，维护最小值和结果的最大值即可。

```Python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2:
            return 0
        minPrice = prices[0]
        ret = 0
        for i in range(1, len(prices)):
            ret = max(ret, prices[i] - minPrice)
            minPrice = min(minPrice, prices[i])
        return ret
        
        
```

