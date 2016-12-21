[原题](https://leetcode.com/problems/valid-perfect-square/)

题意：

判断一个数字是不是完全平方数，但是不能使用sqrt。

使用二分找到最接近sqrt的数字，然后平方判断即可。


```
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        l, r = 1, num//2 + 1
        while l < r:
            mid = (l + r) // 2
            if mid ** 2 > num:
                r = mid
            elif mid ** 2 < num:
                l = mid + 1
            else:
                return True
        return l * l == num
        
```
