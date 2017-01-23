[原题](https://leetcode.com/problems/ugly-number/)

题意：

因子只有2,3,5的数字是丑数，1也是，判断一个数字是不是丑数。

```Python
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        for x in [2, 3, 5]:
            while num % x == 0:
                num = num / x
        return num == 1
```