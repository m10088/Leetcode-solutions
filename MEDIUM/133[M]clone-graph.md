[原题](https://leetcode.com/problems/clone-graph/)

题意：

深度克隆一个无向图。


给定一个入口节点，返回深度克隆之后的结果。


使用一个hash进行保存，如果是C++可以将键值设置成指针，但是如果是python，可以将键值设置成id，因此，如果一个点，已经被copy过了，就可以直接跳过。


递归风格的代码如下。


```Python
# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    def __init__(self):
        self.visited = {}
        
    def cloneGraph(self, node):
        if not node:
            return None
        if node.label in self.visited:
            return self.visited[node.label]

        clone = UndirectedGraphNode(node.label)
        self.visited[node.label] = clone
            
        for n in node.neighbors:
            clone.neighbors.append(self.cloneGraph(n))
        return clone
        
```