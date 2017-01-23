[原文](https://leetcode.com/problems/pascals-triangle/)

题意：

求杨辉三角：

```Python
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:return []
        ret = [[0] * x for x in range(1, numRows + 1)]
        print ret
        ret[0][0] = 1
        for i in range(1, numRows):
            for j in range(0, i+1):
                ret[i][j] = ret[i-1][j] + ret[i-1][j-1] if 0 < j < i else 1
        return ret
```