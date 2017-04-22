[原题](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii)

题意

题解

```Python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n < 2: return 0
        # 一共有n+1个分割点frwd[i]代表的是分成两部分 [0~i]和[i+1~n-1]
        frwd, back = [0] * (n+1), [0] * (n+1)
        frwd[0], frwd[1] = 0, 0
        miner = prices[0]
        for i in range(2, n+1):
            if prices[i-1] < miner:
                frwd[i] = frwd[i-1]
                miner = prices[i-1]
            else:
                frwd[i] = max(frwd[i-1], prices[i-1] - miner)
        
        back[n], back[n-1] = 0, 0
        maxer = prices[n-1]
        for i in range(n-2,-1,-1):
            if prices[i] > maxer:
                back[i] = back[i-1]
                maxer = prices[i]
            else:
                back[i] = max(back[i+1], maxer - prices[i])
        
        #print frwd
        #print back
        
        ret = 0
        for i in range(0, n+1):
            ret = max(ret, frwd[i] + back[i])
        return ret
        

```