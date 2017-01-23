[原题](https://leetcode.com/problems/set-matrix-zeroes/)

题意：


给定一个二维的数组，其中有0和1,如果检测到是0， 那么就将这个元素所在的行和列全部置为0。

首先想到的就是，为行和列开两个数组，分别记录当前的行和列是不是被置为0了。


但是算法的空间复杂度是O（m+n）的显然不是最好的。


其实可以使用数组的第一行和第一列来代替这两个新开的数组，那么原来的第一行和第一列状态应该怎么保存呢？

再使用两个额外的变量即可。



```Python
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        fc, fr = False, False
        if not matrix: return 0
        n, m = len(matrix), len(matrix[0])
        for i in range(n):
            for j in range(m):
                if matrix[i][j] != 0: continue
                if not i: fr = True
                if not j: fc = True
                matrix[0][j] = matrix[i][0] = 0
        
        for i in range(1, n):
            for j in range(1, m):
                if matrix[0][j] == 0 or matrix[i][0] == 0: matrix[i][j] = 0
        
        if fc:
            for i in range(0, n):
                matrix[i][0] = 0
                
        if fr:
            for j in range(0, m):
                matrix[0][j] = 0
        
```