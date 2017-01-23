[原题](https://leetcode.com/problems/summary-ranges/)

题意：

使用字符串描述数组中的元素情况。

如

```
given [0,1,2,4,5,7], return ["0->2","4->5","7"].
```
模拟即可。

```Python
class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums: return []
        tmp = []
        l, r = 0, 0
        nx, n = 1, len(nums)
        while nx < n:
            if nums[nx] == nums[r] + 1:
                r = nx
            else:
                tmp.append((l, r))
                l, r = nx, nx
            nx += 1
        tmp.append((l, r))
        ret = []
        for item in tmp:
            if item[0] == item[1]:
                ret.append(str(nums[item[0]]))
            else:
                ret.append(str(nums[item[0]]) + '->' + str(nums[item[1]]))
        return ret
```