[原题](https://leetcode.com/problems/battleships-in-a-board/)

题意：


船的宽度是1，而且不相互碰着，数一下，一共有多少条船。




对于每个点，判断上面的情况和左边的情况即可。
为了省去边界条件的判断，使用hashing即可。


```
class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        cnt = 0
        if not board: return cnt
        n = len(board)
        m = len(board[0])
        hashing = set()
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'X':
                    first, second = (i-1, j), (i, j-1)
                    if first not in hashing and second not in hashing:
                        cnt += 1
                    else:
                        pass
                    hashing.add((i, j))
        return cnt
```