[原题](https://leetcode.com/problems/heaters)

题意:

有一些房子，和一些加热设备。

为了保证所有的房子都能被加热，那么这些加热设备的最小半径值多少。


题解:

将加热设备排序，然后对于每一个房子，找离这个房子最近的左右两个加热设备。然后为了能被加热找那个小的就行了，但是最后注意是为了“保证”所有的都被加热，那么从所有的最下值中找最大的。

优化：二分查找，提高效率。

```Python
class Solution(object):
    def search_floor_ceiling(self, nums, target):
        n = len(nums)
        assert nums[0] == float('-inf')
        assert nums[-1] == float('inf')
        res, lo, hi = None, 0, n
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] < target:
                lo = mid + 1
                res = lo
            else:
                hi = mid
                res = hi
        # 找到的是一个中间的结果
        l, r = res, res
        while nums[l] > target: l -= 1
        while nums[r] < target: r += 1
        return nums[l], nums[r]
        
    
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters = [float('-inf')] + heaters + [float('inf')]
        heaters=sorted(heaters)
        n = len(heaters)
        # 函数：找到两个数字使得 x<=target<=y 并且x尽量的大，y尽量的小，要求lg(N)级别，如果是动态的呢？
        # 对每一个heaters计算abs(x-target)和abs(y-target)，当然注意特殊的情况，这两个距离应该只要满足一个就行，
        # 因此总是取那个比较小的，每个house都有一个值，所有的值里面最大的那个就是结果了。
        res = 0
        
        for house in houses:
            left, right = self.search_floor_ceiling(heaters, house)
            radius = min(abs(house - left), abs(right - house))
            res = max(res, radius)
        return res
```