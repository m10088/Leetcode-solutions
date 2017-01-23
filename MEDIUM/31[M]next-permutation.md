[原题](https://leetcode.com/problems/next-permutation/)

题意：

1-n的一共n个不同的数字，求他们的下一个排列是什么。

题解：

这个题目之前在《离散数学及其应用》这本书山看到过。

例如例子：1 2 3 5 4 2的下一个排列。应该是 1 2 2 4 3 2。

算法是这样的，先从后往前找到nums[i] < nums[i+1]的第一个数字，然后再i后面找到比nums[i]大的数字里面的最小的一个数字，然后交换nums[i]和这个数字。

最后将所有的数字重新排列。

```Python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) < 2: return
        n = len(nums); i = n-2
        while i >= 0 and nums[i] >= nums[i+1]: i -= 1
        
        # 找到i后面的比a[i]大的最小的数字和他的索引
        miner, miner_index = float('inf'), -1
        for x in range(i, n):
            if nums[x] > nums[i] and nums[x] < miner:
                miner, miner_index = nums[x], x
        
        nums[i], nums[miner_index] = nums[miner_index], nums[i]
        nums[i+1:] = sorted(nums[i+1:])
```
