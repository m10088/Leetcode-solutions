[原题](https://leetcode.com/problems/longest-increasing-subsequence/)

题意：

最长上升子序列。

O(n^2)的算法。

```C++
DP状态转移方程:
D[i] = max{1, D[j] + 1} (j = 1, 2, 3, ..., i-1 且 A[j] < A[i])
解释一下这个方程，i， j在范围内:
如果 A[j] < A[i] ，则D[i] = D[j] + 1
如果 A[j] >= A[i] ，则D[i] = 1
```

O(nlogn)的算法。

dp[i]:=以长度为i+1的上升子序列中，末尾元素的最小的值。

```Python
# O(nlogn)写法1：dp[i]存长度为i + 1的上升子序列中末尾元素的最小值
# fill(dp, dp + n, inf);
# for(i = 0; i < n; i++) {
#     *lower_bound(dp,dp + n, a[i]) = a[i];
# }
# printf(“%d\n”, lower_bound(dp, dp + n, inf)– dp);

class Solution(object):
    
    def lower_bound(self, lister, lo, hi, target):
        """return the index of lower_bound"""
        res = 0
        while lo < hi:
            mid = (lo + hi) // 2
            if lister[mid] < target:
                lo = mid + 1
                res = lo
            else:
                hi = mid
                res = hi
        return res
        
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [float('inf')] * n
        for num in nums:
            tar_index = self.lower_bound(dp, 0, n, num)
            dp[tar_index] = num
        return self.lower_bound(dp, 0, n, float('inf'))
        
        
        
```

