[原题](https://leetcode.com/problems/subsets-ii/)

题意：

给定一个集合，找所有的子集，子集不用索引表示，用值表示，因此可能产生，重复，你的工作就是如何避免这种重复。

```
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        nums = sorted(nums)
        res = []
        def dfs(start, tmp):
            res.append(tmp[:])
            for i in range(start, n):
                if i > start and nums[i] == nums[i-1]: continue
                tmp.append(nums[i])
                dfs(i+1, tmp)
                tmp.pop()
        tmp = []
        dfs(0, tmp)
        return res
            
```

这种方法实际上是从一个网友的combnation—sum那里学来的，很有意思的解法，以前我采用的方式，一般是迭代的过程步进大小是1，但是这种方法，明显不能处理，重复的情况。

但是上面这种解法，灵活的处理了这个问题。