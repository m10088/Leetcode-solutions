[原题](https://leetcode.com/problems/hamming-distance)

题意:

两个数字的海明距离。

题解:

```
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        
        return sum([int(i) for i in bin(x ^ y)[2:]])
        
```