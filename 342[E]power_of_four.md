[原题](https://leetcode.com/problems/power-of-four/)

题意：

判断一数字是不是4的幂。


一个数字是4的幂，有两个条件：
是2的幂。
最高位的那个1，应该在偶数的位置上。


```
class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num > 0 and (num&(num-1))==0 and (num&(0xAAAAAAAA))==0
```

