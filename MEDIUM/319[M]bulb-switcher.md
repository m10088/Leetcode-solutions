[原题](https://leetcode.com/problems/bulb-switcher/)

题意：

```
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
```

[详细-题解-知乎](https://www.zhihu.com/question/35485418/answer/78274979)


如果一个数字的因子的个数是奇数个，那么最后一定是亮着的。

因此问题转化为一个数字的因子的个数是奇数的等价条件是什么？

这个数字是完全平方数字。


1-n之间有多少个完全平方数字？


```Python
class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        # reference 
        # https://www.zhihu.com/question/35485418/answer/78274979
        return int(n**0.5)
```
