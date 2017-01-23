[原题](https://leetcode.com/problems/decode-ways/)

题意：

a-z分别编码为1-26，那么给定一串数字，确定一共有几种编码方式。

如果dp记录一直到当前数字一共有多少种编码方式。


注意的点

如果当前的数字是0,那么一定不能独立的形成字符。
如果和前面的数字组合，是01、02这种形式的或者是27,28这种大于26的也不行。




```Python
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if not n: return 0
        dp = [0] * (n+1)
        dp[0] = 1
        # specail case attention
        dp[1] = 1 if s[0] != '0' else 0
        for i in range(1, n):
            first, second = dp[i], dp[i-1]
            can_independent = 1 if s[i] != '0' else 0
            can_mix = 1 if 10 <=int(s[i-1:i+1]) <= 26 else 0
            dp[i+1] = can_independent * dp[i] + can_mix * dp[i-1]
        return dp[n]
```

