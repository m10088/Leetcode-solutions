[原题](https://leetcode.com/problems/search-insert-position/)

题意：

找到在有序的数组中的插入位置。


实现lower-bound

```
class Solution(object):
    def searchInsert(self, a, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res = -1
        lo, hi = 0, len(a)
        while lo < hi:
            mid = (lo + hi) // 2
            if a[mid] < target:
                lo = mid + 1
                res = lo
            else:
                hi = mid
                res = hi
        return res
                
```


