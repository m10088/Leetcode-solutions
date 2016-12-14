[原题](https://leetcode.com/problems/water-and-jug-problem/)

题意：



给定两个桶，大小分别是a和b，水是无穷的，如何通过合理的倾倒将，倒出z的水来。

注意最后的z升水，应当保留在x和y中。


很容易走到bfs的误区中。


主要是数学证明，如果x和y的最大公约数是c，那么c的倍数是已经能够倒出来的。

因此也就有了下面的代码。


```
class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        
        from fractions import gcd
        return z == 0 or x + y >= z and z % gcd(x, y) == 0
            
```