[原题](https://leetcode.com/problems/word-pattern/)

题意：

给定一个字符串，和一个str的列表，看看str和char之间能不能建立一个双射。

维护两个dict即可。


```Python
class Solution(object):
    def wordPattern(self, pattern, string):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        string = string.split(' ')
        if len(pattern) != len(string): return False
        c_s, s_c = dict(), dict()
        for i in range(len(pattern)):
            c = pattern[i]
            s = string[i]
            if c not in c_s and s not in s_c:
                c_s[c] = s
                s_c[s] = c
            elif c in c_s and c_s[c] == s and s in s_c and s_c[s] == c:
                pass
            else:
                print c, s
                return False
        return True
            
            
```