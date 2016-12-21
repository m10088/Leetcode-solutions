[原题](https://leetcode.com/problems/longest-common-prefix/)

题意：

给定string的数组，求所有的字符串的最长公共前缀。

```
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs: return ''
        def ok_with(strs, index):
            just_one = set()
            for string in strs:
                just_one.add(string[index])
            return len(just_one) == 1
        min_len = min([len(string) for string in strs])
        start = 0
        while start < min_len and ok_with(strs, start):
            start += 1
        return strs[0][0:start]
        
```
