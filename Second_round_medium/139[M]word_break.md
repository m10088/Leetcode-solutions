[原题](https://leetcode.com/problems/word-break/)


题意：

看一个字符串能不能分割成几个段，而且每个段都在给定的字典中。


题解：

使用dp即可。

dp保存到当前是不是能够分割，然后根据前面确定出来的状态确定现在的状态。


```
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        if not s or not wordDict: return False
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        for i in range(0, len(s)):
            for j in range(0, i+1):
                if dp[j] and s[j:i+1] in wordDict:
                    dp[i+1] = 1
                    break
        return dp[len(s)] == 1
        
        
                
```