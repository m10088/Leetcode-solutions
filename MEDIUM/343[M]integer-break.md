[原题](https://leetcode.com/problems/integer-break/)


题意：


将一个数字分成x份，x大于等于2，然后将这些数字相乘，求最大值。


先假设成是double类型的，进行数学求导后发现，x = n / e的时候最大，考虑到是整数，所以可以认为是每一份是3的时候是最大的。


但是这里需要简单的判断下余数，保证是 3 3 4，而不是 3 3 3 1。

```Python
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        # we can prove the fact "that the size of every piece is e(2.7)" is the best  choice
        
        if n == 2: return 1
        if n == 3: return 2
            
        d = n // 3
        x = n % 3
        if x == 0: return 3 ** (d)
        if x == 1: return 3 ** (d-1) * 4
        if x == 2: return 3 ** (d) * 2
        
```
