[原题](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

题意：

在旋转的数组中找最小的值。

旋转数组的定义：

类似这种：

```
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
```


分析二分查找，但是为了确定下一个扫描的区间，我们需要和最右的元素进行比较，（如果和开始的元素进行比较，是不对的）。


```
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
            if nums[mid] >= nums[r]:
                return helper_recursive(mid+1, r)
            else:
                return helper_recursive(l, mid)
        return helper_recursive(0, len(nums)-1)
```