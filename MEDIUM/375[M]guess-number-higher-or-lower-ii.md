[原题](https://leetcode.com/problems/guess-number-higher-or-lower-ii)

题意:
```
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
```

一到n之间需要花费多少钱能保证最后猜对。

题解:

考虑1-n之间至少需要多少花费才能保证猜对？

关键问题是：

下一步我们猜那个数字，才能花的钱最少，因此需要枚举一下子。

在1-n之间尝试枚举哪一个数字花费的钱少。

假如选择了i，那么为了保证能够猜对，需要在两边中选择一个大的。

这个题目涉及到最大最小的关系，比较复杂，应该仔细思考。

```
class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        
        def dfs(l, r, cache):
            if (l, r) in cache: return cache[(l, r)]
            if l >= r: return 0
            mmin = float('inf')
            for k in range(l, r+1):
                tmp = max(dfs(l, k-1, cache), dfs(k+1, r, cache)) + k
                mmin = min(mmin, tmp)
            cache[(l, r)] = mmin
            return mmin
        
        cache = dict()
        return dfs(1, n, cache)
```