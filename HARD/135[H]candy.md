[原题](https://leetcode.com/problems/candy)

题意

题解

```Python
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        left, right = [1]*n, [1]*n
        for i in range(1, n):
            if ratings[i]>ratings[i-1]:
                left[i] = left[i-1] + 1
        
        for i in range(n-2, -1, -1):
            if ratings[i]>ratings[i+1]:
                right[i] = right[i+1] + 1
        ret = 0
        for i in range(n):
            ret += max(left[i], right[i])
        return ret
        
```