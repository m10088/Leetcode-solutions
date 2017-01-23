[原题](https://leetcode.com/problems/excel-sheet-column-number/)

题意：

给定一个excel表示的列，给出他的实际的号码。


分别计算出，x位字母的时候，最多可以表示多少个，然后加上偏移量，即可。

```Python
class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        before = 0
        for i in range(len(s)):
            before += (26 ** i)
        
        left = 0
        for i in range(len(s)):
            e = (len(s) - i - 1)
            left += (ord(s[i]) - ord('A')) * 26 ** e
        
        return before + left
```