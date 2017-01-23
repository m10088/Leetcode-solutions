[原题](https://leetcode.com/problems/powx-n/)

实现幂函数。


注意n可能是小于0的数字，合理的变换即可。
并使用快速幂。


```Python
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0: return 1
        if n < 0: return self.myPow(1/x, -n)
        if n % 2 == 0:
            return self.myPow(x, n//2) ** 2
        else:
            return self.myPow(x, n//2) ** 2 * x
        
```