[原题](https://leetcode.com/problems/arranging-coins/)

题意：

n个硬币摆成阶梯的形状，求第几行不是满的。

```x(x+1)/2 ≤ n < (x+1)((x+1)+1)/2```

Which, using the other formula, turns into 

```x ≤ (sqrt(8n+1) - 1) / 2 < x+1```

So we indeed get the right answer by rounding down 

```(sqrt(8n+1) - 1) / 2.```



we can use binary search as well.

```
class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int((-1 + (1 + 8 * n) ** 0.5) / 2)
```
根据硬件和编译器的各种优化，sqrt函数是O（1）级别的。
