[原题](https://leetcode.com/problems/super-pow/)


题意：

给定a和b，b以数组的形式给出，求a^b % M。

其实这道题目不用快速幂，就可以解决。

根本的方法就是利用同余的性质进行一步一步的抽象。

注释中写的很清楚。

```Python
M = 1337
class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        b = b[::-1]
        def calculate_square(x, base):
            ret = 1
            for i in range(base):
                ret = ret * x
                ret = ret % M
            return ret
        
        # 首先计算一个数字的0次方，10次方，100次方，1000次方，统计到一个数组中
        n = len(b)
        dp = [None] * n
        dp[0] = a % M
        for i in range(1, n): dp[i] = calculate_square(dp[i-1], 10)
        # 然后分别乘以b位置上的基数，重新计算
        # print dp
        for i in range(0, n): dp[i] = calculate_square(dp[i], b[i])
        # print dp
        res = 1
        for i in range(n):
            res *= dp[i]
            res = res % M
        return res
        
```
