[原题](https://leetcode.com/problems/interleaving-string)

题意

题解

```
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        
        n, m, o = len(s1), len(s2), len(s3)
        if m+n != o: return False
        
        dp = [[-1] * (m+1) for i in range(n+1)]
        
        def dfs(i, j): # 判断第1~i个字符与第1~j个字符是不是interleaving的
            if dp[i][j] != -1: return dp[i][j]
            
            if i == 0:
                dp[i][j] = True if s2[:j] == s3[:j] else False
            elif j == 0:
                dp[i][j] = True if s1[:i] == s3[:i] else False
            else:
                if s1[i-1] == s3[i+j-1] and s2[j-1] != s3[i+j-1]:
                    dp[i][j] = dfs(i-1, j)
                elif s1[i-1] != s3[i+j-1] and s2[j-1] == s3[i+j-1]:
                    dp[i][j] = dfs(i, j-1)
                elif s1[i-1] != s3[i+j-1] and s2[j-1] != s3[i+j-1]:
                    dp[i][j] = False
                else:
                    dp[i][j] = dfs(i-1, j) or dfs(i, j-1)
            return dp[i][j]
            
        return dfs(n, m)
        
        
```