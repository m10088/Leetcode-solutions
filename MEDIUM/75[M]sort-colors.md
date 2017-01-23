[原题](https://leetcode.com/problems/sort-colors/)

题意：

一共三个数字0,1,2，乱序，将他们排好序。

题解：

计数排序。

```Python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        red, white, blue = 0, 0, 0
        for color in nums:
            if color == 0: red += 1
            if color == 1: white += 1
            if color == 2: blue += 1
        cur = 0;
        while red:
            nums[cur], cur, red = 0, cur + 1, red - 1
        while white:
            nums[cur], cur, white = 1, cur + 1, white - 1
        while blue:
            nums[cur], cur, blue = 2, cur + 1, blue - 1
```