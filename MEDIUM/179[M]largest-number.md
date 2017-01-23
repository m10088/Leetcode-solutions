[原题](https://leetcode.com/problems/largest-number)

题意:

给定一组数字。[3, 30, 34, 5, 9]，将他们排列成字符串，然后找那个最大的字符串。

对于个数相同的两个数字，直接，按照字典序比较就行。

如果两个数字个数不相同，并且一个数字是另一个的前缀，那么就应该将两个数字拼接，对比一下，然后判断。




题解:


```Python
class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        nums = [str(num) for num in nums]
        def _cmp(x, y):
            n = min(len(x), len(y))
            for i in range(n):
                if x[i] < y[i]:
                    return -1
                elif x[i] > y[i]:
                    return 1
            # 如果程序运行到这里说明其中的一个数字，一定是另一个的前缀
            return -1 if int(x + y) < int(y + x) else 1
            
        
        nums = sorted(nums, cmp= _cmp, reverse=True)
        res = ''.join(nums)
        return res if res[0] != '0' else '0'
```


