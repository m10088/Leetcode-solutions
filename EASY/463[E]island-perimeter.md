[原题](https://leetcode.com/problems/island-perimeter/)

题意：

一个岛是有连续的正方形小格子组成的，并且这些小格子的内部没有lake，求岛的周长。


思路就是考虑每个方格的上面和左边的情况，一共可以分成3中情况，使用hashing可以避免边界条件检查。


```
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        hashing = set()
        ret = 0
        n = len(grid)
        if not n: return 0
        m = len(grid[0])
        
        for i in range(n):
            for j in range(m):
                if not grid[i][j]: continue
                # if up have and left have
                up, left = (i-1, j), (i, j-1)
                if up in hashing and left not in hashing or up not in hashing and left in hashing:
                    ret += 2
                if up not in hashing and left not in hashing:
                    ret += 4
                else:
                    ret += 0
                hashing.add((i, j))
        return ret
```