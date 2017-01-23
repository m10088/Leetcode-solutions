[原题](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)


题意：

买卖股票问题的第二版本。

不限制完成的次数，但是两次交易之间不能重叠。

扫描数组，相邻发现增量的时候，增加到结果中即可。

```Python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        s = 0
        if len(prices) <= 1: return s
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                s += (prices[i] - prices[i-1])
        return s
        
```
