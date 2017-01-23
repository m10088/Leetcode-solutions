[原题](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

题意:

买卖股票问题的升级版。

两次交易不交叉，之间最少休息一天。


题解:

状态机思想。

定义A，B，C三个状态。

A->B 是买了。
A->A 是先不买等待。

B->C 是卖了并进入冷却状态。
B->B 买了之是先不卖，等待。

C->A 是从冷却状态走出来。


保存每次活动之后的三个状态（也就是三个状态的金钱是多少）。

进行状态转移。

```Python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if not n: return 0
        tmp = [0] * n
        # 状态机思想，dp代表处于某种特定状态下（第i天之后）的手上金额的数量
        dp0, dp1, dp2 = tmp[:], tmp[:], tmp[:]
        dp0[0], dp1[0], dp2[0] = 0, -prices[0], 0
        for i in range(1, n):
            dp0[i] = max(dp0[i-1], dp2[i-1])
            dp1[i] = max(dp1[i-1], dp0[i-1]-prices[i])
            dp2[i] = dp1[i-1] + prices[i]
        return max([dp0[n-1], dp1[n-1], dp2[n-1]])
```
