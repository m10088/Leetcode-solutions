[原题](https://leetcode.com/problems/assign-cookies)

题意:


有n个孩子对饼干的需求是a1, a2, ... an, 现在有m个饼干大小是 b1, b2, ... , bm, 求最多能满足多少个孩子。


题解:

两个数组排序之后，进行贪心即可。

```Python
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        res = 0
        i = 0
        for e in s:
            if i == len(g):
                break
            if e >= g[i]:
                res += 1
                i += 1
        return res
```

从小到大枚举饼干，记录已经满足的孩子的指针。
