[原题](https://leetcode.com/problems/minimum-height-trees/)

题意：

给定一棵树，指出以哪一个node作为根，树的高度才最小。


方法很巧妙，类似剥圆葱，的样子，不断的将最外层的叶子节点，删除，同时删除相对应的那条边。


```

class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        degree = dict()
        for edge in edges:
            fir, sec = edge[0], edge[1]
            if fir in degree: degree[fir].append(sec)
            else: degree[fir] = [sec]
            if sec in degree: degree[sec].append(fir)
            else: degree[sec] = [fir]
        recx, recy = None, None
        while len(degree) > 1:
            tmp = degree.copy()
            for key, value in degree.items():
                if len(value) == 1:
                    tmp[value[0]].remove(key)
                    del tmp[key]
                    recx, recy = value[0], key
            degree = tmp
        # 看最后剩余的元素
        li = list(degree)
        return li if li else [recx, recy]
        

```