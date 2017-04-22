[原题](https://leetcode.com/problems/find-the-duplicate-number)

题意：

题解：

```Python
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return []
        elif len(nums) == 1: return nums[0]
        l, r = 1, len(nums)-1
        
        while l < r:
            mid = (l + r) // 2
            # 分成两部分[l, mid]~[mid+1, r]
            count = 0
            for num in nums:
                if num<=mid:# 每次只能确定某个数字的哪一侧，但是如果是和已经确定的区间结合起来，就能逐渐缩小范围
                    count += 1
            if count <= mid:
                l = mid + 1
            else:
                r = mid
        return l
                
```