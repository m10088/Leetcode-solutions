[原题](https://leetcode.com/problems/wiggle-subsequence)

题意:

从一组数字中选择一个子数组，满足波动的性质，求这个子数组的最大长度是什么？

题解:


```
class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 这道题目贪心即可，排好序列之后，我们只选择波峰和波谷中的元素即可
        
        # 预处理，将连续的相同的数字保留一个
        def pre(nums):
            res = []
            for i in range(len(nums)):
                if i == 0 or nums[i] != nums[i-1]:
                    res.append(nums[i])
            return res
            
        nums = pre(nums)
        n = len(nums)
        if n <= 2: return n
        
        counter = 1
        
        def find_max(begin):
            while begin + 1 != n and nums[begin + 1] > nums[begin]: begin += 1
            return begin
                
        def find_min(begin):
            while begin + 1 != n and nums[begin + 1] < nums[begin]: begin += 1
            return begin
            
        if nums[0] < nums[1]: # 先找最大的，然后找最小的
            idx = 0
            while True:
                idx, counter = find_max(idx + 1), counter + 1
                if idx == n - 1: break
                idx, counter = find_min(idx + 1), counter + 1
                if idx == n - 1: break
        else:
            idx = 0
            while True:
                idx, counter = find_min(idx + 1), counter + 1
                if idx == n - 1: break
                idx, counter = find_max(idx + 1), counter + 1
                if idx == n - 1: break
        
        return counter
```

