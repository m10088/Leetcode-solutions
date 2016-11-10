[原题](https://leetcode.com/problems/combinations/)

题意：

求1-n中的k个数字的组合有哪些？

这里使用了```C(n,k) = C(n-1, k-1) + C(n-1, k)```的公式。


```
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        if n == k or k == 0:
            return [[i for i in range(1, k + 1)]]
        else:
            res1 = self.combine(n-1, k-1)
            for item in res1:
                item.append(n)
            res2 = self.combine(n-1, k)
            return res1 + res2
        
```

一般的回溯的解决方案。

```
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        ret = []
        def dfs(tmpRes, depth, cur):
            if depth == k:
                # print tmpRes
                ret.append(tmpRes[:])
                return
            if cur == n + 1:
                return
            else:
                # select cur
                tmpRes[depth] = cur
                dfs(tmpRes, depth + 1, cur + 1)
                # don't select cur
                dfs(tmpRes, depth, cur + 1)

        tmpRes = [0] * k
        dfs(tmpRes, 0, 1)
        return ret
```


