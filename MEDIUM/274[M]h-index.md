[原题](https://leetcode.com/problems/h-index/)

题意：

这一个题目最关键的是理解题意：


翻译过来就是，这个列表中，有几个数字满足一个性质。

这个性质的描述：

某个数x。数组中大于x的数字的个数是a个，那么这个性质就是a <= x。

因此可以这样解决：

将数字从大到小排序，从从开头开始扫描，一直找打一个数字 不满足这个性质，即可，已经扫描过的数字个数就是要找的结果。

为什么这么做可以呢？

如果排序后a在b的前面，加入b满足了这个性质，那么a一定也是满足这个性质的，由于这种单调的性质，因此自然可以想到二分的方法解决。

```Python
class Solution(object):
    
      
    def hIndex(self, nums):
        """
        :type citations: List[int]
        :rtype: int
        """
        nums = sorted(nums, reverse=True)
        n = len(nums)
        def ok(x):
            return x+1 > nums[x]
        l, r = 0, n
        while l < r:
            mid = (l + r) // 2
            if ok(mid):
                r = mid
            else:
                l = mid + 1
        return l
```