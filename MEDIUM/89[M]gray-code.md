[原题](https://leetcode.com/problems/gray-code/)

题意：

生成格雷码。

找规律即可。

codetelleverything

```Python
class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n == 0: return [0]
        last = self.grayCode(n-1)
        adder = 2 ** (n-1)
        for i in range(2**(n-1)-1, -1, -1):
            last.append(adder + last[i])
        return last
            
```