[原题](https://leetcode.com/problems/count-and-say/)

题意：

数数字，1221，读作1个1，2个2，1个1，递推为112211，从1开始n次递推之后的数字。

```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        
        def say(s):
            """s_is_already_read_strings"""
            res = []
            ret = ''
            tmpRes = [s[0]]
            for i in range(1, len(s)):
                if s[i] != s[i-1]:
                    res.append(tmpRes)
                    tmpRes = [s[i]]
                else:
                    tmpRes.append(s[i])
            res.append(tmpRes)
           
            for item in res:
                ret += (str(len(item)) + item[0])
                
            return ret
        
        
        s = '1'
        for _ in range(n-1):
            s = say(s)
        return s
```
