[原题](https://leetcode.com/problems/number-of-segments-in-a-string/)

题意：

判断一个字符串中有几个部分，使用py的正则表达式即可。

```
class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        ret = re.split(r'\s+', s.strip())
        if len(ret) == 1 and ret[0] == '': return 0
        else: return len(ret)
```