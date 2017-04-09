[原题](https://leetcode.com/problems/merge-intervals)

题意：

题解：

```
# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals: return []
        def _cmp(x, y):
            if x.start < y.start: return -1
            elif x.start > y.start: return 1
            else: return 0
        
        intervals.sort(cmp=_cmp)
        rb, re = intervals[0].start, intervals[0].end
        ret = []
        for i in range(1, len(intervals)):
            b, e = intervals[i].start, intervals[i].end
            if b <= re:
                re = max(re, e)
            else:
                ret.append(Interval(rb, re))
                rb, re = b, e
        ret.append(Interval(rb, re))
        return ret
        
            
            
```