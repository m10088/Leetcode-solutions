[原题](https://leetcode.com/problems/reverse-integer/)

题意：在**int**范围内反转一个数字，超过，就返回0

```Python
class Solution(object):
    def reverse(self,x):
        reversedInt=int(str(x)[::-1]) if x>=0 else int('-'+str(x)[1:][::-1])
        #Python doesn't have INT overflow but just to handle the case when the reversed string is not in the 32-bit Int limit 
        return reversedInt if (-1)*2**31<reversedInt<(2**31-1) else 0
```
