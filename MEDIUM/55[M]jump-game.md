[原题](https://leetcode.com/problems/jump-game/)


题意：

数组中的每个元素代表可以跳跃的范围最大是多大，问能不嫩跳跃到最后一个元素。


例如：

```
A = [3,2,1,0,4], return false.
```

分析：

维护一个当前能够跳跃到的最大位置即可，对于扫描的每个位置，如何在最大位置的范围之内，那么就尽量的更新维护的那个值。

```Python
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n <= 1: return True
        now_max_index = 0 + nums[0]
        for i in range(1, n):
            # if this position is in the now_max_index
            if i <= now_max_index:
                now_max_index = max(now_max_index, i + nums[i])
        
        return now_max_index >= n-1
```