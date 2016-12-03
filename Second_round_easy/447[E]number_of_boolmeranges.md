[原题](https://leetcode.com/problems/number-of-boomerangs/)

题意：

给定很多的点，求这些点中等腰三角形的个数。注意，等腰三角形的点的顺序是要考虑的。


因此直接对每个点，进行统计相同的距离的点的个数即可。

```
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def dis(point1, point2):
            return (point1[0]-point2[0])**2 + (point1[1]-point2[1])**2 
        mp = [dict() for point in points]
        n = len(points)
        counter = 0
        for i in range(n):
            for j in range(n):
                if i == j: continue
                distance = dis(points[i], points[j])
                if distance not in mp[i]: mp[i][distance] = 1
                else: mp[i][distance] += 1
            #print mp[i]
            for key, value in mp[i].items():
                counter += (value) * (value-1)
        
        return counter
```