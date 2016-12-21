[原题](https://leetcode.com/problems/maximum-product-subarray/)

题意：


数组中连续区间的最大的积是多少。

题目一开始使用区间dp，比较繁琐，但是后来发现和那个最大连续区间和的题目有点相似，但是需要注意，因为负负得正，因此我们需要额外的维护一个最小值。

maxi[i] : 以i结尾的区间之积的最大值。


```
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # but this should be an easy problem
        n = len(nums)
        if not n: return 0
        mini, maxi = [0] * n, [0] * n
        mini[0], maxi[0], ret = nums[0], nums[0], nums[0]
        for i in range(1, n):
            maxi[i] = max([maxi[i-1] * nums[i], mini[i-1] * nums[i], nums[i]])
            mini[i] = min([mini[i-1] * nums[i], maxi[i-1] * nums[i], nums[i]])
            ret = max(ret, maxi[i])
        return ret
    
```