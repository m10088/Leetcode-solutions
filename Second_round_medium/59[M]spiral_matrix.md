[原题](https://leetcode.com/problems/spiral-matrix-ii/)

题意：

给定一个完全平方数，返回一个二维的数组，这个数组中的数字是盘旋的排布的。

模拟即可。

```
class Solution(object):
    # same idea as Part 1...
    def generateMatrix(self, n):
        if n==0: return []
        # initialize...
        l = 0; r = n-1; u = 0; d = n-1
        right = True; down = False; left = False; up = False
        matrix = [[None for i in range(n)] for j in range(n)]
        i=0; j=0; k=1
        # traverse the spiral, taking a turn whenever restricted by a boundary
        while k<=n*n:
            matrix[i][j] = k
            k += 1
            if right:
                if j+1<=r:
                    j += 1
                else: # must go down
                    right = False; down = True; u += 1; i += 1
            elif down: 
                if i+1<=d:
                    i += 1
                else: # must go left
                    down = False; left = True; r -= 1; j -= 1
            elif left: 
                if j-1>=l:
                    j -= 1
                else: # must go up
                    left = False; up = True; d -= 1; i -= 1
            elif up:
                if i-1>=u:
                    i -= 1
                else: # must go right
                    up = False; right = True; l += 1; j += 1
        return matrix
```