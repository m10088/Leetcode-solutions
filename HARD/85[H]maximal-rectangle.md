[原题](https://leetcode.com/problems/maximal-rectangle)

题意

题解

```Python
class Solution(object):
    def largestRectangleArea(self, h):
        """
        :type heights: List[int]
        :rtype: int
        """
        # 对于每个i，维护一个L[i] = j | j < i && h[j] < h[i] && j 是最大的
        # 对于每个j，维护一个R[i] = j | j > i && h[j] < h[i] && j 是最小的
        n = len(h)
        L, R = [-1] * n, [n] * n
        stack, ret = [], 0
        for i in range(n):
            while len(stack) and h[stack[-1]] >= h[i]:
                stack.pop(-1)
            if len(stack) == 0: L[i] = -1
            else: L[i] = stack[-1]
            stack.append(i)
        stack = []
        for i in range(n-1, -1, -1):
            while len(stack) and h[stack[-1]] >= h[i]:
                stack.pop(-1)
            if len(stack) == 0: R[i] = n
            else: R[i] = stack[-1]
            stack.append(i)
        for i in range(n):
            ret = max(ret, h[i] * (R[i]-L[i]-1))
        return ret
    
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix: return 0
        n, m = len(matrix), len(matrix[0])
        sum = [0] * m
        ret = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '0':
                    sum[j] = 0
                else:
                    sum[j] += 1
            ret = max(ret, self.largestRectangleArea(sum))
        return ret
        
        
        
```