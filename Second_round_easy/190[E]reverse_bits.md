[原题](https://leetcode.com/problems/reverse-bits/)

题意：

反转unsigned_int的二进制表示。

hint：python支持bit opr.

```
def reverseBits(self, n):
        ret = 0
        for i in range(32):
            b = (n>>i) & 1
            ret += b<<(31-i)
        return ret
```