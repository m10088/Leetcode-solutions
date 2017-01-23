[原题](https://leetcode.com/problems/add-binary/)

题意：

二进制相加之后，给出和的str形式。

```Python
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a = [int(x) for x in a]
        b = [int(x) for x in b]
        
        maxer = 1 + max(len(a), len(b))
        a = [0] * (maxer - len(a)) + a
        b = [0] * (maxer - len(b)) + b
        carry = 0
        ret = ''
        for i in range(0, maxer):
            index = maxer - i - 1
            tmp = a[index] + b[index] + carry
            carry = tmp / 2
            ret += str(tmp %2 )
        ret = ret[::-1]
        if ret[0] == '0': return ret[1:]
        else: return ret
```

细节问题较多。
