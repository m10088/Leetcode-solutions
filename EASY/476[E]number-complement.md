[原题](https://leetcode.com/problems/number-complement/)

题意：

二进制位数统计。简单。

题解：

```
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        res = 0
        for bit in bin(num)[2:]:
            res = res * 2 + 1 if bit == '0' else res * 2
        return res
```
