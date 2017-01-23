[原题](https://leetcode.com/problems/climbing-stairs/)

题意：

斐波那契数列。根据f(n) = f(n-1) + f(n-2)

递归超时，改为迭代即可。

```Python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0: return 0
        f_n_1, f_n_2 = 0, 1
        for _ in range(n):
            f_n_2, f_n_1 = f_n_2 + f_n_1, f_n_2
        return f_n_2
```