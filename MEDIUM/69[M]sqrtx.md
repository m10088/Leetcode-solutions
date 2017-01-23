[原题](https://leetcode.com/problems/sqrtx/)

题意：不用库求开放数字。


当然可以使用二分查找。

但这里我们使用牛顿迭代法。

```Python
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        r = x
        while r*r > x:
            r = (r + x/r) / 2
        return r 
```

牛顿迭代法是有通用的公式的，但是这里求平方根，是一个特例。

具体的数学证明可以[参考这里](http://blog.chinaunix.net/uid-24118190-id-75267.html)

