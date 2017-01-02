[原题](https://leetcode.com/problems/find-all-duplicates-in-an-array)

题意:


给定一个数组大小是n，然后里面的每个元素的大小都是 1<=a[i]<=n，找到所有重复的数字。


题解:


这道题目的要求是使用固定的空间，并且线性复杂度。

关键是记录是不是重复必须使用额外的一个数组，但是也有一种方式，就是使用原来的数字的负数，标记已经出现过了，哈哈，聪明哦。

```
class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n, res = len(nums), []
        for i in range(n):
            tar = abs(nums[i])
            if nums[tar-1] < 0:
                res.append(tar)
            else:
                nums[tar-1] = -nums[tar-1]
        return res
```
