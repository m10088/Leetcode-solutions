[原题](https://leetcode.com/problems/contains-duplicate/)

题意：

数组中是不是有重复的元素？

hash即可。

```
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        seter = set()
        for item in nums:
            if item in seter:
                return True
            else:
                seter.add(item)
        return False
```

