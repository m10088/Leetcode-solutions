[原题](https://leetcode.com/problems/length-of-last-word/)

题意：

最后一个单词的长度；

主要是python处理字符串的一些用法。

```Python
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip(' ')
        print s
        strs = re.split(r'\s+', s)
        if len(strs) == 0: return 0
        else: return len(strs[-1])
```
