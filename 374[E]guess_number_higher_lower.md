[原题](https://leetcode.com/problems/guess-number-higher-or-lower/)

题意：

1-n之间猜一个数，给定一个api，让你知道是猜的是大还是小。


虽然不知道这个题目，oj是如何判断的，但是很明显是二分的题目。1A。

```
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 1, n
        while l < r:
            mid = l + (r - l) // 2
            if guess(mid) == 0:
                return mid
            elif guess(mid) > 0:
                # l = mid wrong!
                l = mid + 1
            else:
                r = mid
        return l
```