[原题](https://leetcode.com/problems/patching-array)

题意

题解

```
class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        # 首先明白下面几点
        
        # 假如已经有了 1, 2, 4，那么就能够凑出7来了，下一步添加的数字应该是8，因为8是第一个不能凑出来的，
        # 但是一旦添加了8，那么1-15就全部能凑出来了。
        
        # 如果没有干扰，那么就是等比数列。
        
        # 但是如果考虑数组中的元素。
        
        
        
        sz = len(nums)
        i = 0
        cur = 0
        counter = 0
        
        while cur < n: # 当前能够凑出的数组最大值如果超过了n那么就退出
            if i<sz and nums[i] <= cur + 1: # 假如已经有了1,2,4,能凑出7，那么如果下一个元素不超过8就可以考虑加进来
                cur += nums[i]
                i += 1
            else:
                counter += 1
                cur = cur * 2 + 1

        return counter
        
```