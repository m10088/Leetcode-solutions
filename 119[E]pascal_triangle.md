[原题](https://leetcode.com/problems/pascals-triangle-ii/)

题意：

求杨辉三角的第n行，空间O(1),直接使用公式计算即可，但是这样时间复杂度很大，观察可知，C(n, k)和C(n, k-1)存在数学关系，因此可以同时优化时间和空间。

```

class Solution(object):
    def C(self, n, k):
        if k == 0: return 1
        if 2 * k > n:
            return self.C(n, n-k)
        else:
            down, up, ret = 1, (n-k) + 1, 1
            for _ in range(k):
                ret = ret * up / down
                up, down = up + 1, down + 1
            return ret
                
            
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        return [self.C(rowIndex, x) for x in range(0, rowIndex+1)]
```

优化之后的

```
C[k,i] = C[k,i-1]*(k-i+1)/i
```
