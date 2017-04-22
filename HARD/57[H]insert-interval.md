[原题](https://leetcode.com/problems/insert-interval)

题意

题解

```Python
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
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        # python list insert(idx)，在idx前面插入一个数据
        flag = False
        for i in range(len(intervals)):
            if intervals[i].start > newInterval.start:
                flag = True
                intervals.insert(i, newInterval)
                break
        if not flag:
            intervals.append(newInterval)
        
        return self.merge(intervals)
        
        
```