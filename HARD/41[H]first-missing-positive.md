[原题](https://leetcode.com/problems/first-missing-positive)

题意

题解

```Python
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n):
            if nums[i] < 0:
                nums[i] = 0
        
        def make_right(i): # 让nums[i]回到自己正确的位置上
            rec = i
            next_idx = i
            next_elem = nums[i]
            while 1<=next_elem<=n: # and next_idx + 1 != next_elem:
                                   # 这里为什么不需要加上，因为位置正确的地方不是同一个等价类，因此不会发生这种情况
                next_idx = next_elem-1
                next_elem = nums[next_idx]
                nums[next_idx] = -1
            if nums[rec] >= 0: # 如果没有这个判断条件，[2, 1]这个case会WA掉
                nums[rec] = 0 
            
        for i in range(n):
            if nums[i] <= 0 or nums[i] == i + 1: continue
            make_right(i)
        for i in range(n):
            if nums[i] == 0: return i + 1
        return n + 1
            
        
```