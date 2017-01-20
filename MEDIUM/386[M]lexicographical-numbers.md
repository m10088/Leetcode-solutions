[原题](https://leetcode.com/problems/lexicographical-numbers/)

题意：

1-n之间的数字进行string处理之后，按照字典序排序。

题解：


这个题目很像trie树，如果真的建立一颗trie树的话，那么最后的结果遍历这个tries树即可，但是实际上，没有必要建立这棵树，直接按逻辑进行dfs即可，dfs分支结束的条件就是大于n。

```
class Solution(object):
     def lexicalOrder(self, n):
        def dfs(k, res):
            if k <= n:
                res.append(k)
                t = 10*k
                if t <= n:
                    for i in range(10):
                        dfs(t + i, res)
        res = []
        for i in range(1, 10):
            dfs(i, res)
        return res
```

这里有个很有意思的问题，如果dfs的过程不带有res，那么TLE/MLE，这可能与Python的垃圾回收机制有关。