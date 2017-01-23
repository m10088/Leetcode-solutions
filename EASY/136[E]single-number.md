[原题](https://leetcode.com/problems/single-number/)

题意：

一些数字，除了其中一次，其他的都出现了两次，将这个出现一次的数字找出来。

异或运算的交换律的性质，如果重新排列这些数字，让singlenumber排到最后，那么进行异或之后的结果就是singlenumber。

python_solution
```Python
class Solution(object):
    def Xor(self, a, b):
        return a ^ b
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(self.Xor, nums)
        
```

