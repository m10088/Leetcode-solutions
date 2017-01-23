[原题](https://leetcode.com/problems/fraction-to-recurring-decimal)

题意:

给定一个分数，返回他的小数形式，循环小数，需要标记出循环节。

题解:

不断地做除法就行，并且记录当时的除数和商，如果找到余数是0了，那么说明是一个有限小数。

如果余数之前出现过了，那么之前出现余数的那个位置，到当前的位置就是循环节了。

容易忽视的问题就是：

假如 算的是 1 / 6，那么第一个余数是1，而不是4。

```Python
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        
        def get_index(li, val):
            for i in range(len(li)):
                if li[i] == val: return i
            return None
        
        def fetch_demical(a, b):
            up, left = [], [a]
            a = a * 10
            while True:
                u, l = a // b, a % b
                up.append(u)
                
                if l == 0: # 说明是一个非循环小数
                    return ''.join([str(x) for x in up])
                    
                if l in left: # 说明是一个循环小数
                    idx = get_index(left, l)
                    first =  ''.join([str(x) for x in up[0:idx]])
                    second = '(' + ''.join([str(x) for x in up[idx:]]) + ')'
                    return first + second
                    
                
                else:
                    left.append(l)
                
                a = l * 10
        
        # 标记是不是负数
        factor = 1 if numerator * denominator < 0 else 0
        numerator, denominator = abs(numerator), abs(denominator)
        
        # 如果没有小数部分
        divor, left = numerator // denominator, numerator % denominator
        print divor, left
        if left == 0: return '-' * factor + str(divor)
        
        # 如果有小数部分
        else: return '-' * factor + str(divor) + '.' + fetch_demical(left, denominator)
```

其他的细节，假分数，负数，简单的处理一下就行。