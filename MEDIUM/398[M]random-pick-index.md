[原题](https://leetcode.com/problems/random-pick-index/)

题意：

给定一个数字，随机的返回一个所给数字的索引，概率是随机的。

这个题目是有内存限制的，因此不能复制整个输入的数组。

因此需要不断的随机挑选，一直到选到目标的数字为止。

```Python
class Solution(object):

    def __init__(self, nums):
        """
        
        :type nums: List[int]
        :type numsSize: int
        """
        self.nums = nums
        

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        tmp = random.randint(0, len(self.nums)-1)
        while self.nums[tmp] != target:
            tmp = random.randint(0, len(self.nums)-1)
        return tmp


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)

```

