[原题](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

题意：

在一个矩阵中找到第k小的元素。


这个矩阵的行元素是递增的，列元素是递增的。


假设目标数字是x，找比x小的数字有多少个，然后二分查找即可。



```Python
def upper_bound(a, target):
    res = -1
    lo, hi = 0, len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] > target:
            hi = mid
            res = hi
        else:
            lo = mid + 1
            res = lo
    return res
            
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        if not matrix: return None
        n = len(matrix)
        lo, hi = matrix[0][0]-1, matrix[n-1][n-1]+1
        def found_less_or_equal_number(target):
            _sum = 0
            for lst in matrix:
                _sum += upper_bound(lst, target)
            return _sum
        
        while lo < hi:
            mid = (lo + hi) // 2
            target_number = found_less_or_equal_number(mid)
            
            print mid, target_number
            
            if  target_number <= k - 1:
                lo = mid + 1
            else:
                hi = mid
                
        return lo
            
                
            
                
                
```