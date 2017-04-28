[原题](https://leetcode.com/problems/number-of-digit-one)

题意

题解

```Python
class Solution(object):
    def countDigitOne(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0: return 0
        # base = [1, 20, 300, 4000...]
        x = str(x)
        base, n = [], len(x)
        for i in range(20):
            base.append(i * 10 ** (i-1))
        ret = 0
        for i in range(n):
            # 从低到高第k位,k = 0, 1, 2, 3, ...
            k, num = n - i - 1, int(x[i])
            adder = 10 ** k + base[k] * num if num > 1 else base[k] * num
            
            if num == 1: # 额外的情况
                last = 1 if x[i+1:] == '' else int(x[i+1:]) + 1 
                adder += last
            # print adder
            ret += int(adder)
        return ret
        
        
```