[原题](https://leetcode.com/problems/n-queens)

题意

题解

```
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        ver = [0] * (n + 1) # 记录水平的方格有没有被占用
        ang1 = [0] * (2 * (n + 1)) # 记录主对角线的方格有没有被占用
        ang2 = [0] * (2 * (n + 1)) # 记录在负对焦香的方格有没有被占用
        rec = [-1] * (n + 1)
        ret = []
        # 通过记录构造最后的解
        def store():
            tmp, res = [['.'] * (n) for i in range(n)], []
            for i in range(n):
                tmp[rec[i]][i] = 'Q'
            for i in range(n):
                res.append(''.join(tmp[i]))
            ret.append(res)
            
        def dfs(j): 
            if j == n:
                store()
                return
            # 对于每一个列，分别尝试放置每一个方格
            for i in range(0, n):
                if ver[i] == 0 and ang1[i+j] == 0 and ang2[i-j+n] == 0: #可以放
                    ver[i], ang1[i+j], ang2[i-j+n] = 1, 1, 1
                    rec[j] = i
                    dfs(j + 1)
                    rec[j] = -1
                    ver[i], ang1[i+j], ang2[i-j+n] = 0, 0, 0
        dfs(0)
        return ret
```