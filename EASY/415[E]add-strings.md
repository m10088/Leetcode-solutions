[原题](https://leetcode.com/problems/add-strings/)

题意：

求str表示的两个数字的和（str形式）。


当然使用库函数，一行代码解决，但是不允许使用库函数。

当然可以，分别定义int2string，string2int的函数，但是效率太低。

```
class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i, j, carry, res = len(num1) - 1, len(num2) - 1, 0, ''
        while i >= 0 or j >= 0 or carry > 0:
            sum = 0
            if i >= 0:
                sum += ord(num1[i]) - ord('0')
                i -= 1
            if j >= 0:
                sum += ord(num2[j]) - ord('0')
                j -= 1
            sum += carry
            carry = sum / 10
            sum %= 10
            res = str(sum) + res
        return res
```
