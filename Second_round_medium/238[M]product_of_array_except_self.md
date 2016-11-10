[原题](https://leetcode.com/problems/product-of-array-except-self/)

题意：

数组其他的元素的乘积，放在当前的元素上，不能使用除法运算。


其实，思路很简单，从正向的使用一次乘法累乘，从负向的使用一次乘法累乘即可。

```
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        p = 1
        n = len(nums)
        output = []
        for i in range(0,n):
            output.append(p)
            p = p * nums[i]
        p = 1
        for i in range(n-1,-1,-1):
            output[i] = output[i] * p
            p = p * nums[i]
        return output
```