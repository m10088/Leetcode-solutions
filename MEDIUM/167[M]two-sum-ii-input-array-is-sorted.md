[原题](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

题意：

两个有序的数组。

进行two—sum的查找。

思路：贪心，双指针即可。

```Python
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(numbers) - 1
        while l < r:
            if numbers[l] + numbers[r] == target:
                return [l+1, r+1]
            elif numbers[l] + numbers[r] < target:
                l += 1
            else:
                r -= 1
```