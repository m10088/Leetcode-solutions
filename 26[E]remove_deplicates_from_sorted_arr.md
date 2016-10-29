[原题](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

题意：

删除排好序的数组中重复的元素，原地，Ｏ(1)空间复杂度。

注意，其他元素的值无所谓。只要保证前m个数字是升序，而且是不同的即可。

因此可以使用双指针，前面的指针只要比后面的指针的数据大，就写入数据，推进慢指针。


```
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        i = 1
        for n in nums:
            if n > nums[i-1]:
                nums[i] = n
                i += 1
        nums = nums[:i]
        return i
```
