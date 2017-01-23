[原题](https://leetcode.com/problems/combination-sum/)


题意：

For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

也就是说，同一个位置的数字可以出现任意的次数，因为题目中说了集合中的数字是不会重复的，因此，也就不会产生重复。


```Python

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates = sorted(candidates)
        n = len(candidates)
        res = []
        def dfs(start, remain, tmp):
            #print 'now', start, remain
            if remain < 0: return
            if remain == 0:
                res.append(tmp[:])
                return
            for i in range(start, n):
                tmp.append(candidates[i])
                dfs(i, remain-candidates[i], tmp)
                tmp.pop()
        
        tmp = []
        dfs(0, target, tmp)
        return res
            
```

建议和combination-sum-ii和subsetii对比。

