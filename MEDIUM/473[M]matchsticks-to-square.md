[原题](https://leetcode.com/problems/matchsticks-to-square)

题意:

给定一个数组，判断能不能将这个数组分成4部分，然后每部分的和是相等的。（拼接正方形）。

题解:

开始的时候以为这个题目有什么技巧，但是最后发现数据范围比较小。

dfs暴力即可。

优化：

dfs的时候先判断哪个数字大的，这样可以有效的减少dfs的层数。

先倒序一下，然后dfs即可，尝试每根木棍放到四个组，如果最后成功那么退出。

```
class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if not n: return False
        if sum(nums) % 4 != 0: return False
        target = sum(nums) // 4
        nums = sorted(nums, reverse=True)
        stick = [0] * 4
        def dfs(index):
            if index == n: return stick == [target] * 4
            for i in range(4):
                if stick[i] + nums[index] <= target:
                    stick[i] += nums[index]
                    if dfs(index+1): return True
                    else: stick[i] -= nums[index]
            
            return False
        return dfs(0)
```

