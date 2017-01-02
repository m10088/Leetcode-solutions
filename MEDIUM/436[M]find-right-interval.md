[原题](https://leetcode.com/problems/find-right-interval)

题意:

简单的二分查找。
```
Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
```


题解:

```
# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def lower_bound(self, lo, hi, target, nums, _cmp):
        res = None
        while lo < hi:
            mid = (lo + hi) // 2
            if _cmp(nums[mid], target) < 0:
                lo = mid + 1
                res = lo
            else:
                hi = mid
                res = hi
        return res
    

    
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        n = len(intervals)
        if not n: return []
        a = [(interval.start, i) for i, interval in enumerate(intervals)]
        # 按照第一个值大小排好序，如果大小相同，那么按照第二个值的大小排序
        
        def _cmp(x, y):
            if x[0]==y[0] and x[1]==y[1]: return 0
            return -1 if x[0]<y[0] or x[0]==y[0] and x[1]<y[1] else 1
        # 学会了sorted的cmp参数的使用                                    
        a = sorted(a, cmp=_cmp)
        print a
        res = []
        for interval in intervals:
            tmp = self.lower_bound(0, n, (interval.end, -1), a, _cmp)
            tmp = -1 if tmp == n else a[tmp][1]
            res.append(tmp)
        return res
```

这个题目唯一的收获就是学会了python如何给sort函数传参数。
