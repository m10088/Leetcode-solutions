[原题](https://leetcode.com/problems/combination-sum-ii/)


题意：

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]


就是说，同一个位置的数字不能出现两次，同时结果不能有重复的出现。


建议将下面的解法和combination-sum-i、subset_ii进行对比。

```Python

class Solution(object):
    def combinationSum2(self, candidates, target):
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
                if i > start and candidates[i] == candidates[i-1]: continue
                tmp.append(candidates[i])
                dfs(i+1, remain-candidates[i], tmp)
                tmp.pop()
        
        tmp = []
        dfs(0, target, tmp)
        return res
```