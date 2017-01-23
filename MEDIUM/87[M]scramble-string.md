[原题](https://leetcode.com/problems/scramble-string/)

题意：

判断两个字符串是是不是scramble的，scramble的定义详见，原题目链接。

这里使用了记忆化搜索解决。

```Python
class Solution(object):
    cache = {}
    def isScramble(self, s1, s2):
        tmp = (s1, s2)
        if tmp in self.cache:
            return self.cache[tmp]
        if len(s1) != len(s2):
            self.cache[tmp] = False
            return False
        if s1 == s2:
            self.cache[tmp] = True
            return True
        for i in range(1,len(s1)):
            if self.isScramble(s1[:i],s2[:i]) and self.isScramble(s1[i:],s2[i:]) or \
            self.isScramble(s1[:i],s2[-i:]) and self.isScramble(s1[i:],s2[:-i]):
                self.cache[tmp] = True
                return True
        self.cache[tmp] = False        
        return False
```
