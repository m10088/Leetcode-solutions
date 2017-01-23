[原题](https://leetcode.com/problems/search-a-2d-matrix/)

题意：

在一个矩阵中寻找是不是存在一个target的数值。

这个矩阵的每行是递增的，每列是递增的。


```Python
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix: return False
        n, m = len(matrix), len(matrix[0])
        i, j = 0, m - 1
        while i < n and j >= 0:
            if matrix[i][j] == target: return True
            elif matrix[i][j] < target: i += 1
            else: j -= 1
        return False
```
