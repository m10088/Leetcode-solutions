[原题](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons)

题意:

有很多个区间，最少需要多少个点，能“覆盖”所有的区间。


题解:


区间贪心问题，很简单，按照区间的结尾进行排序，每次选择区间的最后一个点，进行贪心即可。

```Python
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        n = len(points)
        if not n: return 0
        def _cmp(first, second):
            # 排列的顺序，首先是按照end，从小到大，如果相同，那么看begin
            if first[1] < second[1]: return -1
            elif first[1] > second[1]: return 1
            else: return 0
        points = sorted(points, cmp=_cmp)
        counter, last = 1, points[0][1]
        for point in points:
            if point[0] <= last <= point[1]: continue
            counter, last = counter + 1, point[1]
        return counter
```
