[原题](https://leetcode.com/problems/contains-duplicate-ii/)

题意：

是否存在两个相等的数字，他们的index分别是i，j，i和j之间的距离小于k。

hash，不断的更新num的位置。即可。

```
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        position = dict()
        for i, num in enumerate(nums):
            if num not in position:
                position[num] = i
            else:
                j = position[num]
                if i - j <= k:
                    return True
                position[num] = i
        return False
```

另外一种解法，set维护一个大小为k的滑动窗口，必须保证，如果窗口内有两个值相等了，那么就返回true。否则返回false。
