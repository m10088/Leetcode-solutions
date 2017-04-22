[原题](https://leetcode.com/problems/max-points-on-a-line)

题意

题解

```Python
# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        def gcd(x, y):
            if y == 0: return x
            else: return gcd(y, x%y)
        
        def get_tuple(i, j):
            dy = points[i].y - points[j].y
            dx = points[i].x - points[j].x
            if dx == 0: return (0, 1)
            else:
                return (dx//gcd(dx, dy), dy//gcd(dx, dy))
        # 注意如果使用斜率，由于精读的原因最后一个case会fail，因此保存这个向量成为一个良好的选择。
        ret = 0
        n = len(points)
        for i in range(n):
            mp = dict()
            same = 1
            for j in range(n):
                if i == j: continue
                p, q = points[i], points[j]
                if p.x == q.x and p.y == q.y: same += 1
                else:
                    ki = get_tuple(i, j)
                    if ki not in mp: mp[ki] = 1
                    else: mp[ki] += 1
            mmax = 0
            for key, value in mp.items():
                mmax = max(mmax, value)
            ret = max(ret, mmax+same)
        return ret
        
```