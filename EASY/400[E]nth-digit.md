[原题](https://leetcode.com/problems/nth-digit/)

题意：

将int的数值从1开始全部变成str类型，排成一列，然后随便说一个第m个数字是什么。

首先，确定范围是在100-999，之间还是1000-9999之间，然后，计算第几个数字的第几位，这里发现，n-1之后处理更加方便。

```Python
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        # first_step: find the range
        i = 1
        total = 0
        while True:
            total += 9 * i * 10 ** (i-1)
            if n <= total: break
            i += 1
        # 10^(i-1) ~ 99...99
        n -= (total - 9 * i * 10 ** (i-1))
        n -= 1
        print i
        print n
        loc = n // i + 10 ** (i-1)
        left = n % i
        return int(str(loc)[left])
        
        
        
```