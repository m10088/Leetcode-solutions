[原题](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii)

题意

题解

```Python
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper_recursive(l, r):
            if l == r:
                return nums[l]
            # find the middle number
            mid = (l + r) // 2
            # compared to the right position is better.
            if nums[mid] > nums[r]:
                return helper_recursive(mid+1, r)
            elif nums[mid] < nums[r]:
                return helper_recursive(l, mid)
            else:
                return helper_recursive(l, r-1)
        return helper_recursive(0, len(nums)-1)
```