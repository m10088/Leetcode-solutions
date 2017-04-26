[原题](https://leetcode.com/problems/maximum-gap)

题意

题解

```Python
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # 这里为了达到线性时间以及线性空间的目的，可以采用如下的方法：
        # 一共进行31轮。
        # 从低位到高位排序，每轮使用计数排序。（稳定的）
        # 每轮的空间和时间复杂度都是O（n）
        # 详细可以参考 https://github.com/zhanglanqing/Introduction-to-algorithms/tree/master/doc/%E6%8E%92%E5%BA%8F/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F
        ret = 0
        v = sorted(nums)
        for i in range(1, len(nums)):
            ret = max(ret, v[i]-v[i-1])
        return ret
        
            
        
            
        
        

```