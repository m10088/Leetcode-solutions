[原题](https://leetcode.com/problems/spiral-matrix/)

题意：


给定一个二维的数组，对其进行旋转的遍历，结果存放到一维的数组。

模拟即可：

```
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        n = len(matrix)
        if not n: return []
        m = len(matrix[0])
        ret = []
        rowbegin, rowend = 0, n-1
        colbegin, colend = 0, m-1
        while rowbegin<=rowend and colbegin<=colend:
            # to right
            for j in range(colbegin, colend+1): ret.append(matrix[rowbegin][j])
            rowbegin += 1
            # down
            for j in range(rowbegin, rowend+1): ret.append(matrix[j][colend])
            colend -= 1
            # to left
            if rowbegin<=rowend:
                for j in range(colend, colbegin-1, -1): ret.append(matrix[rowend][j])
                rowend -= 1
            if colbegin<=colend:
                for j in range(rowend, rowbegin-1, -1): ret.append(matrix[j][colbegin])
                colbegin += 1
        return ret
        
            
```