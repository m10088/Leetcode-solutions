[原题](https://leetcode.com/problems/single-number-ii)

题意:

除了一个数字出现了1次之外其他的数字都出现了3次，找到这个singlenumber。

题解:

将这些数字分解二进制，然后32个位置分别统计一共有多少个1，如果这个位置上的1的个数能被3整除，那么singlenumber在这一位上没有分量，否则有分量，根据求出的singlenumber的分量，最后还原这个singlenumber。

类似的原理，可以不是仅仅使用在3上，其他也是可以的。


```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 平移这些int元素
        nums = [num + 2 ** 31 for num in nums]
        dp = [0] * 32
        for num in nums:
            for i in range(32):
                    dp[i] = dp[i] + 1 if num & (1 << i) else dp[i]
        
        result = 0
        for i in range(32):
            if dp[i] % 3 != 0:
                result += 2 ** i
        return result - 2 ** 31
        
```
