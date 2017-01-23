[原题](https://leetcode.com/problems/container-with-most-water/)


题意：


给定一些数字，索引和数值组成一个键值对，然后使用任何两个数值，作为高度，索引差，作为宽度，组成一个长方形。求长方形的最大的面积是多少？


首先ｌ和ｒ分别是选择最两边的数值。

然后不断的进行向中间进行收缩的策略，进行遍历。

但是收缩的时候完全可以进行优化。

如果

```
a[l] < a[r]
```
那么已经下一步一定是l向右移动而不是r像左边移动。

```Python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n, maxer = len(height), 0
        if n <= 1: return maxer
        l, r = 0, n-1
        while l < r:
            h = min(height[l], height[r])
            maxer = max(maxer, (r-l)*h)
            if height[l] <= height[r]: l+=1
            else: r-=1
        return maxer
        
        

```