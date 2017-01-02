[原题](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array)

题意:

数组长度是n，1<=a[i]<=n，找到在1-n之间缺少的那些数字。

题解:

常数空间，线性时间。

使用数组位置取反，代表制定的元素a[i]位置已经出现了。

```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i, x in enumerate(nums):
            x = abs(x)
            if nums[x-1] > 0:
                nums[x-1] = -nums[x-1]
        res = []
        for i, x in enumerate(nums):
            if x > 0:
                res.append(i+1)
        return res
```
