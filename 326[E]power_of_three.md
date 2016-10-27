[原题](https://leetcode.com/problems/power-of-three/)


不用递归的方式判断一个数字是不是3的幂。


```
class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # 1162261467 is 3^19,  3^20 is bigger than int  
        return ( n>0 and  1162261467%n==0)
```

