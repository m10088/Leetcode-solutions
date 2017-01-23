[原题](https://leetcode.com/problems/gas-station)

题意:

有n个加油站，用个圈连起来，因此一共有n段路，每个position记录当前加油站的油，和接下来的路程需要消耗的油。

问：从那个加油站开始能够遍历晚整个圆圈上的加油站。

题解:

这个题目思路算是比较清晰，首先找到一个“能够作为开始的点”，然后模拟就行，如果能走完，那么就是返回这个点，如果到了i点，走不下去了，那么我们从i+1点开始尝试。

最后看尝试的点回到了原来的位置，那么就是失败的。


有两点需要注意：

如果A开始B是第一个无法到达的点，那么AB之间的点i，也不能到达B，因为至少从A开始的到达i的时候油是>=0的。现在从i开始油是0，当然无到达。

将所有的gas和cost相加，如果cost > gas，那么无解，反之，一定有解。

```Python
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(cost) > sum(gas): return -1
        tank, start, n = 0, 0, len(gas)
        for i in range(n):
            tank += (gas[i]-cost[i])
            if tank < 0:
                start = i + 1
                tank = 0
        return start
    
```

