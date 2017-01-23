[原题](https://leetcode.com/problems/course-schedule-ii/)


题意：

给定课程的依赖关系，进行课程排序，拓扑排序即可。


```Python
class Solution(object):
    def findOrder(self, n, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        point_to = dict()
        in_degree = [0] * n
        for i in range(n): point_to[i] = []
        for link in prerequisites:
            point_to[link[0]].append(link[1])
            in_degree[link[1]] += 1

        stack = []
        out = []
        for i in range(n):
            if in_degree[i] == 0: stack.append(i)
    
        while stack != []:
            back = stack.pop(-1)
            print back
            out.append(back)
            for to in point_to[back]:
                in_degree[to] -= 1
                if in_degree[to] == 0: stack.append(to)
        
        return out[::-1] if len(out) == n else []
        
```