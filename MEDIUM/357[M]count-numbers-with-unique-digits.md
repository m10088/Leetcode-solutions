[原题](https://leetcode.com/problems/count-numbers-with-unique-digits/)


题意：


一个n位数，每个位置上的数字都不相同，一共有多少种数字。

简单的排列组合，不能前导0，如果n是5，那么就是 

9x9x8x7x6


```
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if not n: return 1
        def fact(n):
            return 1 if n == 1 else n*fact(n-1)
        def fx(n):
            if n == 1: return 10
            elif n > 10: return 0
            else: return 9 * fact(9) / fact(9-n+1)
        
        n = min(n, 10)
        return sum([fx(x) for x in range(1, n+1)])
        
```