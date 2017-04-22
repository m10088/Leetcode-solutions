[原题](https://leetcode.com/problems/n-queens-ii)

题意

题解

```Python

class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        ver = [0] * (n + 1) # 记录水平的方格有没有被占用
        ang1 = [0] * (2 * (n + 1)) # 记录主对角线的方格有没有被占用
        ang2 = [0] * (2 * (n + 1)) # 记录在负对焦香的方格有没有被占用
        totalCnt = [0] # 只能使用这个黑技巧了
        def dfs(j): 
            if j == n:
                totalCnt[0] += 1
                return
            # 对于每一个列，分别尝试放置每一个方格
            for i in range(0, n):
                if ver[i] == 0 and ang1[i+j] == 0 and ang2[i-j+n] == 0: #可以放
                    ver[i], ang1[i+j], ang2[i-j+n] = 1, 1, 1
                    dfs(j + 1)
                    ver[i], ang1[i+j], ang2[i-j+n] = 0, 0, 0
        dfs(0)
        return totalCnt[0]
        
                    
                    
```