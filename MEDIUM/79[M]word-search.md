[原题](https://leetcode.com/problems/word-search/)

题意：

这个题目的坑就是，python的二维数组的初始化操作，找了好久的bug。

错误的初始化方式。

```
dp = [[0] * m] * n
```


除此之外就是简答的dfs。
正确的解法。


```Python

class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        n = len(board)
        if not n: return false
        m = len(board[0])
        
        dxdy = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        status = [[0 for col in range(m)] for row in range(n)]
        
        def dfs(cur, i, j):
            # base case
            if cur == len(word): return True
            if not (0 <= i < n and 0 <= j < m): return False
            if status[i][j] == 1: return False
            
            if board[i][j] != word[cur]: return False
            status[i][j] = 1
            for direction in dxdy:
                ni, nj = i + direction[0], j + direction[1]
                if dfs(cur+1, ni, nj): return True
            status[i][j] = 0
            return False
        
        for i in range(0, n):
                for j in range(0, m):
                    if dfs(0, i, j): return True
        return False
            
        
```