[原题](https://leetcode.com/problems/sudoku-solver)

题意

题解

```
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        
        a = [[0] * 9 for i in range(9)]
        # 这里如果传入当前的位置，可以进一步优化算法的复杂度
        def getNextEmpty():
            for i in range(9):
                for j in range(9):
                    if a[i][j] == 0:
                        return (i, j)
            return (-1, -1)
        
        def canPut(num, i, j):
            # 检查同一个行，列，方格的数字
            tmpSetrow, tmpSetcol, tmpSetcell = set(), set(), set()
            for k in range(9):
                tmpSetrow.add(a[i][k])
            for k in range(9):
                tmpSetcol.add(a[k][j])
            for k1 in range(i//3 * 3, i//3 * 3+3):
                for k2 in range(j//3 * 3, j//3 * 3+3):
                    tmpSetcell.add(a[k1][k2])
            return num not in tmpSetrow and num not in tmpSetcol and num not in tmpSetcell
            
        def dfs(i, j):
            # print i, j
            if i==-1 and j==-1: return True
            for num in range(1, 10):
                if canPut(num, i, j):
                    a[i][j] = num
                    if dfs(*getNextEmpty()): return True
                    a[i][j] = 0
            return False
        
        # 为了方便，先将字符转化成数字
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.': a[i][j] = 0
                else:                  a[i][j] = int(board[i][j])
        assert dfs(*getNextEmpty()) == True
        # 最后将数字再转化成字符
        for i in range(9):
            for j in range(9):
                board[i][j] = str(a[i][j])
        
        
        
        
        
        
```