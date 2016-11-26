[原题](https://leetcode.com/problems/multiply-strings/)

题意：

给定两个字符串，代表的是数字，返回相乘之后的结果。

不能使用有关的库函数。

开始的想法就是模拟小学学的竖式相乘的算法，

但是评论区，出现了一种更为巧妙的解法。

![ima](https://drscdn.500px.org/photo/130178585/m%3D2048/300d71f784f679d5e70fadda8ad7d68f)

```
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        m = len(num1)
        n = len(num2)
        pos = [0] * (m + n)
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                _mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                p1 = i + j;
                p2 = i + j + 1;
                _sum = _mul + pos[p2]
                pos[p1] += _sum / 10;
                pos[p2] = (_sum) % 10;
        carry = 0
        ret = ''
        for i in range(m+n-1, -1, -1):
            x, carry = (pos[i] + carry) % 10, (pos[i] + carry) / 10
            pos[i] = x
        k = 0
        while k < m + n and pos[k] == 0: k+=1
        if k == m + n: return '0'
        else: return ''.join([str(x) for x in pos[k:]])
        
        
```