[原题](https://leetcode.com/problems/excel-sheet-column-title/)

题意：

确定excel表格的标题。


先通过不断的累加26的幂，确定目标有几个字母，然后不断的除26，余26，即可，注意的是n要减一。

```Python
class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        i = 0
        sum = 0
        while sum < n:
            i += 1
            sum += 26 ** i
            
        # i is the number of chars
        tar = n - (sum - (26 ** i)) - 1
        s = ''
        for _ in range(i):
            num = tar % 26
            tar = tar / 26
            s += chr(num + ord('A'))
        return s[::-1]
```