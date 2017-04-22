[原题](https://leetcode.com/problems/burst-balloons)

题意

题解

```Python
# 这个题目是区间dp，但是需要逆向考虑，
# 也就是dp[i][j]的含义是：这个区间最后一步考虑够获得的最大收益。
# 如果最后考虑的是[i, j]区间，那么考虑上一步扎破k，
# 就能够转化成其他的两个区间的子问题，
# 而扎破这个k的时候，这个k两边剩余的气球就是i，j

class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        n, a = len(nums) + 2, [1] + nums[::] + [1] # 暂时扩张这个表
        dp = [[-1] * (n+1) for i in range(n+1)]
        
        # 考虑到迭代更新的不方便，使用记忆化搜索
        def dfs(i, j):
            if dp[i][j] != -1: return dp[i][j]
            
            if i+1 == j: 
                dp[i][j] = 0
            elif i+2 ==j: 
                dp[i][j] = a[i] * a[i+1] * a[i+2]
            else:
                maxer = -1
                for k in range(i+1, j):
                    maxer = max(maxer, dfs(i, k) + dfs(k, j) + a[i] * a[k] * a[j])
                dp[i][j] = maxer
            return dp[i][j]
        
        return dfs(0, n-1)
        
            
        
```