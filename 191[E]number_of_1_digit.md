[原题](https://leetcode.com/problems/number-of-1-bits/)

题意：

统计无符号int二进制中1的个数。


传统的方法：

```
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 0
        for i in range(32):
            if n & (1 << i):
                cnt += 1
        return cnt
```
python库解法。

```
def hammingWeight(self, n): 
       return str(bin(n)).count('1')
```