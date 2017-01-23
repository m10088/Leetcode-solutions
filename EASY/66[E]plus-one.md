[原题](https://leetcode.com/problems/plus-one/)

题意：

数组表示的数值，返回+1后的数组形式。

```Python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        ret = [0] * len(digits)
        for j in range(0, len(digits)):
            i = len(digits) - j - 1
            ret[i] = (digits[i] + carry) % 10
            carry = (digits[i] + carry) / 10
        return [1] + ret if carry == 1 else ret
```