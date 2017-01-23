[原题](https://leetcode.com/problems/evaluate-divisionyy)

题意:

给定一些数字之间的倍数关系，并且给定一些查询，无法求得的查询，返回-1,否则返回查询结果。

题解:


这道题目写了好多次，刚开始以为是一棵树，使用并查集去做，后来发现，一个节点不一定仅仅有一个father，因此是一个图。


给定啊a，b之间的关系，我们需要在a，b之间建立一个双向的边，边上记录的是权值。

然后只有在同一个联通分量中，我们才能进行关系查询。

对于一个联通分量，找个入口，假设值为1，然后进行dfs，就能求出，整个分量的其他的点的值了。

优化之后，dfs进行一次就行。

```Python
class Solution(object):
    def calcEquation(self, eqs, vals, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        G = dict()
        for a, b in eqs: G[a], G[b],  = [], []
        
        for i in range(len(eqs)):
            a, b = eqs[i][0], eqs[i][1]
            G[a].append((b, vals[i]))
            G[b].append((a, 1.0 / vals[i]))
        
        # 第二部遍历，并且将他们分成几个集合，并在遍历的过程中求出值
        setid, cost = dict(), dict()
        counter_id = 0
        
        def dfs(p, curid, curcost):

            setid[p], cost[p] = curid, curcost
            for next_point, next_cost in G[p]:
                if next_point not in setid:
                    dfs(next_point, curid, curcost * next_cost)
        
        
        for key, value in G.items():
            if key not in setid:
                dfs(key, counter_id, 1.0)
                counter_id += 1
        
        
        res = []
        for a, b in queries:
            if a not in setid or b not in setid: res.append(-1.0)
            elif setid[a] != setid[b]: res.append(-1.0)
            else: res.append(cost[b]/cost[a])
        return res
```
