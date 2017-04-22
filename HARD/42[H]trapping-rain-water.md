[原题](https://leetcode.com/problems/trapping-rain-water)

题意

题解

```Python
class Solution(object):
    def trap(self, h):
        """
        :type h: List[int]
        :rtype: int
        """
        n = len(h)
        if n <= 2: return 0
        l, r = 0, n-1
        lmax, rmax, ret = 0, 0, 0
        while l < r:
            # 考虑一个累计的过程而不是一下子最后全部求出来
            first, second = h[l], h[r]
            if first > second:
                if second > rmax: rmax = second
                else: ret += (rmax - second)
                r -= 1
            else: # 右边更大
                if first > lmax: lmax = first
                else: ret += (lmax - first)
                l += 1
        return ret
        
        
        
        
```