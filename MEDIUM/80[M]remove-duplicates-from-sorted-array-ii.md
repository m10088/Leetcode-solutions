[原题](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

题意：

一串排好序的数字，要让每个数字重复的次数不超过两次，出现在数组的前面，后面的数字是什么无所谓。


分析发现：

原本以为需要额外开辟一块内存，但是发现直接在原来的数组上进行写入操作就行，因为扫描的速度是大于写入的速度的。


需要额外注意一下开始的特殊情况。

```Python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for n in nums:
            if i < 2 or n > nums[i-2]:
                nums[i] = n
                i += 1
        return i
```