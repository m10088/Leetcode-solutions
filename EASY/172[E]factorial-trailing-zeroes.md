[原题](https://leetcode.com/problems/factorial-trailing-zeroes/)

题意：

n的阶乘的结尾的0的个数。

两种方法。

其实，从"那些数相乘可以得到10"这个角度，问题就变得比较的简单了。
因为2的个数一定是比5多的，因此只要计算1x2x3x4x5x6....xn中有多少个5就行了。

当然，我们想到了下面的算法。

```
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        num = 0
        for i in range(1, n+1):
            j = i
            while j % 5 == 0:
                num += 1
                j = j % 5
        return num
```

TLE了，优化一下，


```Z = N/5 + N /(5*5) + N/(5*5*5).....```

until 

```N/(5的K次方)等于0```

公式中 N/5表示不大于N的数中能被5整除的数贡献一个5，```N/(5*5)```表示不大于N的数中能被25整除的数再共享一个5.......

```
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        num = 0
        while n > 0:
            num += (n//5)
            n = n // 5
        return num
```


