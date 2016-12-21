[原题](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)


题意：

在旋转的数组中找是不是存在一个值。


思路实际上是二分的思想，但是有些情况，显然也是不能实现二分的。


总起来讲一共有四种情况。


code tell everything。


```
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        def helper_recursive(lo, hi, target):
            # empty array
            if lo > hi: return 0  
            # just one element
            if lo == hi: return lo + 1 if nums[lo] == target else 0
            # just happend to be the same
            mid = (lo + hi) // 2
            if nums[mid] == target: return mid + 1
            elif nums[mid] > target:
                if nums[mid] >= nums[lo]: return  helper_recursive(lo, mid-1, target) | helper_recursive(mid+1, hi, target)
                else: return helper_recursive(lo, mid-1, target)
            else:
                if nums[mid] <= nums[lo]: return helper_recursive(lo, mid-1, target) | helper_recursive(mid+1, hi, target)
                else: return helper_recursive(mid+1, hi, target)
                
        return helper_recursive(0, len(nums)-1, target) != 0
```