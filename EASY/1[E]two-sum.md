[原题](https://leetcode.com/problems/two-sum/)

题意：

给定一个数列，寻找两个数字的和，是target，返回他们的下标。

hash方法即可，但是这里有个陷阱，就是[2,1,3]target=4,不要返回[0,0]，要避免这种结果发生，可以边进行hash边进行查找。

```
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        index = dict()
        for i in range(0, len(nums)):
            index[nums[i]] = i
        
        for i in range(0, len(nums)):
            if target-nums[i] in index and index[target-nums[i]] != i:
                return [i, index[target-nums[i]]]
```
