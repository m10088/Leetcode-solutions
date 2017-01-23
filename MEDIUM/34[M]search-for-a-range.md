[原题](https://leetcode.com/problems/search-for-a-range/)

题意：

有序的数组，找target所在的范围。

题解：

lowerbound和upperbound

```Python
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums = [float('-inf')] + nums + [float('inf')]
        n = len(nums)
        def lower_bound(lo, hi, target):
            res = None
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] < target:
                    lo = mid + 1
                    res = lo
                else:
                    hi = mid
                    res = hi
            return res
        
        def upper_bound(lo, hi, target):
            res = None
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] > target:
                    hi = mid
                    res = hi
                else:
                    lo = mid + 1
                    res = lo
            return res
        left, right = lower_bound(0, n, target) , upper_bound(0, n, target)
        # 对二分查找进行适当的修改
        
        return nums[left], nums[right]
  
```
