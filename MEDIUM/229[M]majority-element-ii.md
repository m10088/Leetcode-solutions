[原题](https://leetcode.com/problems/majority-element-ii)

题意:


上一个投票算法的变形。

但是这里有多个候选人。

这个算法看似很巧妙，证明却不简单。

题解:


```Python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        count1, count2, candidate1, candidate2 = 0, 0, float('inf'), float('-inf') # 注意分析开始的情况。
        for n in nums:
            if n == candidate1: count1 += 1
            elif n == candidate2: count2 += 1
            elif count1 == 0: candidate1, count1 = n, 1
            elif count2 == 0: candidate2, count2 = n, 1
            else: count1, count2 = count1 - 1, count2 - 1
        
        return [n for n in (candidate1, candidate2) if nums.count(n) > len(nums) // 3]
```
