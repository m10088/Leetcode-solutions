[原题](https://leetcode.com/problems/subsets/)

题意：

二进制法生成子集。

```
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        ret = []
        for i in range(0, 2**(len(nums))):
            tmpRes = []
            for k in range(0, len(nums)):
                if (i & (1 << k)): tmpRes.append(nums[k])
            ret.append(tmpRes)
        return ret
```

