[原题](https://leetcode.com/problems/game-of-life/)


题意：

给出一个m*n的细胞矩阵，每个细胞都有一个初始状态：生存（1）或死亡（0）。每个细胞的变化都与它周围8个细胞有关，规则如下：

- 当前细胞为存活状态时，当周围存活细胞不到2个时， 该细胞变成死亡状态。（模拟生命数量稀少）

- 当前细胞为存活状态时，当周围有2个或3个存活的细胞时， 该细胞保持原样。

- 当前细胞为存活状态时，当周围有3个以上的存活细胞时，该细胞变成死亡状态。（模拟生命数量过多）

- 当前细胞为死亡状态时，当周围恰好有3个存活细胞时，该细胞变成存活状态。 （模拟繁殖）

写一个函数，根据矩阵当前的状态，计算这个细胞矩阵的下一个状态。

解题方法

在不使用定义新矩阵的情况下，要想解决本问题就需要先定义一组中间状态，中间状态要求能看出一个单元格变化前后两方面的生死情况。

```
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        DEAD = 0; ALIVE = 1
        DEAD_TO_DEAD = 0; ALIVE_TO_ALIVE = 1; ALIVE_TO_DEAD = 2; DEAD_TO_ALIVE = 3
                
        def isAliveOld(obj):
            return obj == ALIVE_TO_ALIVE or obj == ALIVE_TO_DEAD
        def isAliveNew(obj):
            return obj == ALIVE_TO_ALIVE or obj == DEAD_TO_ALIVE
        
        if not board: return
        n, m = len(board), len(board[0])
        for i in range(n):
            for j in range(m):
                counter = 0
                direction = [(-1, 0), (1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (-1, 1), (1, -1)]
                for d in direction:
                    nx, ny = i + d[0], j + d[1]
                    if 0 <= nx < n and 0 <= ny < m and isAliveOld(board[nx][ny]): 
                        counter += 1
                
                    # 如果原来的是存活的状态
                    if isAliveOld(board[i][j]):
                        if counter < 2: board[i][j] = ALIVE_TO_DEAD
                        elif 2 <= counter <= 3: board[i][j] = ALIVE_TO_ALIVE
                        else: board[i][j] = ALIVE_TO_DEAD
                    # 如果原来是死亡的状态
                    else:
                        if counter == 3: board[i][j] = DEAD_TO_ALIVE
                        else: board[i][j] = DEAD_TO_DEAD
        
        for i in range(n):
            for j in range(m):
                board[i][j] = ALIVE if isAliveNew(board[i][j]) else DEAD
        
                    
```
