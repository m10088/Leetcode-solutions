[原题](https://leetcode.com/problems/range-sum-query-immutable/)

题意：

范围求和的查询：

思路，保存前缀和即可。

```
class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        # sum[i] 代表前i个数字的和
        self.sum_ = [0] * (len(nums) + 1)
        for i in range(1, len(nums) + 1):
            self.sum_[i] = nums[i-1] + self.sum_[i-1]
        
        
        

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sum_[j+1] - self.sum_[i]
        
        


# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.sumRange(1, 2)
```