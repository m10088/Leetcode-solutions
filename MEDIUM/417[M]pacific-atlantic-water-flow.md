[原题](https://leetcode.com/problems/pacific-atlantic-water-flow/)


题意：


抽象出来的问题就是，如果一个点，只能到达比他高或者相同高度的点，那么给定一个开始的位置，在这个二维网格中，能到达哪些位置？

bfs或者dfs均可。


```Python
class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        # 分别计算能到达大西洋和太平洋的方格有哪些，即可，方法，可以进行bfs或者进行dfs，这里选择进行bfs
        n = len(matrix)
        if not n: return []
        m = len(matrix[0])
        zeros = [0] * m
        direction = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        vis_pac, vis_alt = [zeros[:] for i in range(n)], [zeros[:] for i in range(n)]
        q = []
        # 将上面和左边的方格放进去
        for j in range(m):
            if (0, j) not in q: q.append((0, j))
        for i in range(n):
            if (i, 0) not in q: q.append((i, 0))
        # bfs
        while q != []:
            fro = q.pop(0)
            vis_pac[fro[0]][fro[1]] = 1
            for d in direction:
                nx, ny = fro[0] + d[0], fro[1] + d[1]
                if 0<=nx<n and 0<=ny<m and vis_pac[nx][ny]==0 and matrix[nx][ny] >= matrix[fro[0]][fro[1]]:
                    q.append((nx, ny))
        
        # 相同的策略
        for j in range(m):
            if (0, j) not in q: q.append((n-1, j))
        for i in range(n):
            if (i, 0) not in q: q.append((i, m-1))
        
        while q != []:
            fro = q.pop(0)
            vis_alt[fro[0]][fro[1]] = 1
            for d in direction:
                nx, ny = fro[0] + d[0], fro[1] + d[1]
                if 0<=nx<n and 0<=ny<m and vis_alt[nx][ny]==0 and matrix[nx][ny] >= matrix[fro[0]][fro[1]]:
                    q.append((nx, ny))
        
        res = []
        for i in range(n):
            for j in range(m):
                if vis_pac[i][j] and vis_alt[i][j]:
                    res.append([i, j])
        return res
        
            
        
```