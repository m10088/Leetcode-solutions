[原题](https://leetcode.com/problems/largest-rectangle-in-histogram)

题意

题解

```
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
        stack = []
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
        
        ret = 0
        
        for i in range(n):
            ret = max(ret, h[i] * (R[i]-L[i]-1))
        return ret
        
        
                
```