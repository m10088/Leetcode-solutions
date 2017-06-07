[原题](https://leetcode.com/problems/wildcard-matching)

题意

题解

```
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        def removeStars(s):
            if not s: return s
            ret = s[0]
            for i in range(1, len(s)):
                if s[i] != '*' or s[i] != s[i-1]:
                    ret += s[i]
            return ret
        
        p = removeStars(p)
        n, m = len(s), len(p)
        dp = [[-1] * (m+1) for i in range(n+1)]
        # print dp
        
        def dfs(i, j):
            
            if dp[i][j] != -1: return dp[i][j]
          
            elif i==0 and j==0:
                dp[i][j] = 1
            elif i>0 and j==0:
                dp[i][j] = 0
            elif i==0 and j>0:
                dp[i][j] = 1 if j==1 and p[j-1]=='*' else 0 # 注意这里特殊情况的处理方法
            else:
                if s[i-1]==p[j-1] or p[j-1]=='?':
                    dp[i][j] = dfs(i-1, j-1)
                elif p[j-1] == '*':
                    
                    ok, k = 0, i
                    while k>=0:
                        if dfs(k, j-1):
                            ok = 1
                            break
                        k -= 1
                    dp[i][j] = ok
                    
                else:
                    dp[i][j] = 0
            
            return dp[i][j]
            
        return True if dfs(n, m)==1 else False
        


```