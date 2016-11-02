[原题](https://leetcode.com/problems/zigzag-conversion/)

题意：

ZigZag变换，锯齿变换。

主要是模拟和python的字符串处理。

```
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or len(s) < 2: return s
        rows = ["" for _ in range(numRows)]
        # when right == True we are going down, when right == False we are going up
        i, right = -1, True
        for ch in s:
            i = i + 1 if right else i - 1
            rows[i] += ch
            right = False if i == numRows-1 else True if i == 0 else right
        return "".join(rows)
```


最后更新right的时候可以分开来写。

