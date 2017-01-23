[原题](https://leetcode.com/problems/reconstruct-itinerary)

题意:

给你一个有向图，可能有重边，给你一个起点，求一个欧拉回路（要求遍历所有的边），假设输入是有效的。


题解:


直接套欧拉回路的模板即可，但是这里有个问题就是最后的哪一个点，显示不出来，简单的修改一下就行了。
```Python
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        # 首先构建一个有向图
        map, res, visited = dict(), [], dict()
        
        # 对图进行初始化
        for fm, to in tickets:
            map[fm], map[to] = [], []
            if (fm, to) not in visited:
                visited[(fm, to)] = 1
            else:
                visited[(fm, to)] += 1
            
        for fm, to in tickets:
            map[fm].append(to)
        for key, value in map.items():
            map[key].sort()
            
        # print map
        
        
        def eular(root):
            for des in map[root]:
                if visited[(root, des)] != 0:
                    visited[(root, des)] -= 1
                    eular(des)
            res.append(root) # 修改了这里原来是，在if条件里面的。
            
        eular('JFK')
        return res[::-1]
```
