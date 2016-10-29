[原题](https://leetcode.com/problems/rectangle-area/)


题意：

两个长方形的坐标是和坐标系平行的。


求两个长方形的并集的面积。

先求交集。

交集可能是空。

交集可能是两个长方形中的一个。

其中一个覆盖另一个。

```
class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        A, C = min(A, C), max(A, C)
        B, D = min(B, D), max(B, D)
        E, G = min(E, G), max(E, G)
        F, H = min(F, H), max(F, H)
        
        
        # no intersection
        if C <= E or G <= A: return (C-A) * (D-B) + (H-F) * (G-E)
        if H <= B or D <= F: return (C-A) * (D-B) + (H-F) * (G-E)
        
        #one cover another
        if A >= E and C <= G and B >= F and D <= H:
            return (G-E) * (H-F)
        if E >= A and G <= C and F >= B and H <= D:
            return (C-A) * (D-B)
        
        # intersection
        overlap = (min(C,G)-max(A,E))*(min(D,H)-max(B,F))
        
        return (C-A) * (D-B) + (H-F) * (G-E) - overlap
        
        
        
```


或者直接统一上述情况，讨论区代码。

```
def computeArea(self, A, B, C, D, E, F, G, H):
    overlap = max(min(C,G)-max(A,E), 0)*max(min(D,H)-max(B,F), 0)
    return (A-C)*(B-D) + (E-G)*(F-H) - overlap
```
