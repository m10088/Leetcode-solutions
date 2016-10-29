[原题](https://leetcode.com/problems/house-robber/)

题意：

一个小偷，偷一个一维数组，不能偷两个相邻的数字。

计算，能偷到的最大的值是多少。

dp[i]代表从1-i能偷到的最多的钱。

每一个位置有两种策咯：

这个不偷，这个偷。

dp[i] = max(dp[i-1], nums[i] + dp[i-2]);

```

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        dp = [0] * (len(nums) + 1)
        dp[1] = nums[0]
        for i in range(2, len(nums)+1):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
        return dp[-1]
        
```

同样是上述的思路，讨论区有人，优化到了空间O(1)。

```
int rob(int num[], int n) {
    int a = 0;
    int b = 0;
    for (int i=0; i<n; i++) {
        if (i%2==0) {
            a = max(a+num[i], b);
        } else {
            b = max(a, b+num[i]);
        }
    }
    return max(a, b);
}
```
