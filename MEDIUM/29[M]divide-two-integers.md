[原题](https://leetcode.com/problems/divide-two-integers)

题意:


不用除法符号在实现除法。

题解:

假设我们需要运算的是 16 / 3。
首先的暴力的解法就是每次减去3，看能减多少次。

但是这种方法太暴力，超时。

因此我们不断的将3扩大二倍（左移），一直到扩到12以后，就不能再扩了，因为之后就会比16大，因此 16 / 3 = 12 / 3 + (16 - 12) / 3。然后只需递归的解决 4 / 3即可。


除此之外，处理一些简单的细节。

```
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        ranger, MAX_INT = (-(1<<31), (1<<31) - 1), (1<<31) - 1
        def mydiv(a, b):
            print a, b
            if a < b: return 0
            x, y = b, 1
            while a > (x << 1):
                x <<= 1 
                y <<= 1
            a -= x
            return mydiv(a, b) + y
        
        # 这里主要是用来判断符号
        factor = 0
        if dividend < 0: factor += 1
        if divisor < 0: factor += 1
        factor = 1 if factor == 1 else 0
        
        res = mydiv(abs(dividend), abs(divisor))
        res = -res if factor else res
        
        return res if ranger[0] <= res <= ranger[1] else MAX_INT
```

