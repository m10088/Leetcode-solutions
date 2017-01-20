[原题](https://leetcode.com/problems/non-overlapping-intervals)

题意:

最少需要移除多少个区间，让所有的区间不相交。

转化一下成为，最多有多少个区间能实现尽量的覆盖。

按照区间的end进行排序贪心即可。

题解:

```
# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        # 和这个题目类似的是，让尽量多的不相交的区间覆盖一个线段
        end = float('-inf')
        erased = 0
        for i in sorted(intervals, key=lambda i: i.end):
            if i.start >= end:
                end = i.end
            else:
                erased += 1
        return erased
```