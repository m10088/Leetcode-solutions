[原题](https://leetcode.com/problems/regular-expression-matching)

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
        # pre-process
        # special case test
        if p.startswith('*'): return False
        def RemoveMultiStars(s):
            if not s: return s
            ret = s[0]
            for i in range(1, len(s)):
                if s[i] != '*' or s[i] == '*' and s[i-1] != '*':
                    ret += s[i]
            return ret
        p = RemoveMultiStars(p)
        t = ''
        marked = [0] * (len(p) + 1)
        for i in range(len(p)):
            if p[i] != '*': t += p[i]
            else: marked[len(t)] = 1
        
        # main-function
        n, m = len(s), len(t)
        dp = [[-1] * (m+1) for i in range(n+1)]
        
        def dfs(i, j):
            # print i, j
            if dp[i][j] != -1: return dp[i][j]
            
            if i==0 and j==0:
                dp[i][j] = 1
            elif i>0 and j==0:
                dp[i][j] = 0
            elif i==0 and j>0:
                if marked[j]==0:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dfs(i, j-1)
            else:
                if marked[j]==0:
                    dp[i][j] = dfs(i-1, j-1) if s[i-1]==t[j-1] or t[j-1]=='.' else 0
                else:
                    # 先判断这个*代表0个的情况
                    first = dfs(i, j-1)
                    second = 0
                    if s[i-1]==t[j-1]:
                        k = i-1
                        while k>=0 and s[k] == s[i-1]:
                            if dfs(k, j-1):
                                second = 1
                                break
                            k -= 1
                    if t[j-1] == '.':
                        k = i-1
                        while k>=0:
                            if dfs(k, j-1):
                                second = 1
                                break
                            k -= 1
                    
                    dp[i][j] = first or second
            return dp[i][j]
     

        return False if dfs(n, m)==0 else True

```