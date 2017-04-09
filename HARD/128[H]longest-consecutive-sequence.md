[原题](https://leetcode.com/problems/longest-consecutive-sequence)

题意

题解

```
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        fa = dict()
        tag = dict()
        for num in nums:
            tag[num] = True
            if num in fa: continue # 这个元素已经存在了
            if num+1 in fa:
                fa[num+1] = num
                tag[num] = False
            if num-1 in fa:
                fa[num] = num-1
                tag[num-1] = False
            else:
                fa[num] = float('inf')
        
        mmax = 0
        for num in nums:
            if not tag[num]: continue
            # print num
            tmp = 1
            while fa[num] != float('inf'): num, tmp = fa[num], tmp+1
            mmax = max(mmax, tmp)
        return mmax
            
```