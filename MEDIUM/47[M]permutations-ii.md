[原题](https://leetcode.com/problems/permutations-ii)

题意:

产生所有不重复的排列。

参考[这篇博客](http://blog.csdn.net/zlqdhrdhrdhr/article/details/51139929)即可。


题解:
```

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        tmp, final = [0] * n, []
        def dfs(cur):
            if cur == n:
                final.append(tmp[:])
                return
            for i in range(0, n):
                if not (i == 0 or nums[i] != nums[i-1]): continue
                c1, c2 = tmp[:cur].count(nums[i]), nums.count(nums[i])
                if c1 < c2:
                    tmp[cur] = nums[i]
                    dfs(cur+1)
        dfs(0)
        return final
```
  
                
                
