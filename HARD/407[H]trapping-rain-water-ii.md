[原题](https://leetcode.com/problems/trapping-rain-water-ii)

题意

题解

```
class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        n = len(heightMap)
        if n == 0: return 0
        m = len(heightMap[0])
        
        visited = [[False for i in range(m)] for j in range(n)]
        from Queue import PriorityQueue
        q = PriorityQueue()
        for i in range(n):
            for j in range(m):
                if i==0 or i==n-1 or j==0 or j==m-1:
                    visited[i][j] = True
                    q.put([heightMap[i][j],i,j])
            
                
        S = 0
        while q.qsize() > 0:
            cell = q.get()
            for (i, j) in [(1,0), (-1,0), (0,1), (0,-1)]:
                x = cell[1] + i
                y = cell[2] + j
                if x in range(n) and y in range(m) and not visited[x][y]:
                    S += max(0, cell[0] - heightMap[x][y])   # how much water at the cell
                    q.put([max(heightMap[x][y],cell[0]),x,y])
                    visited[x][y] = True
        return S
        
        
        
```