[原题](https://leetcode.com/problems/edit-distance)

题意

题解

```Python
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        n, m = len(word1), len(word2)
        dp = [[-1] * (m+1) for i in range(n+1)]
        def dfs(i, j): # [1~i]和[1~j]相同的个数
            if dp[i][j] != -1: return dp[i][j]
            if i == 0 and j == 0:
                dp[i][j] = 0
            elif i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            else:
                first = dfs(i, j-1) + 1
                second = dfs(i-1, j) + 1
                third = dfs(i-1, j-1) if word1[i-1]==word2[j-1] else dfs(i-1, j-1) + 1
                # 这个地方注意如果最后的两个字母相同，那么删除的时候删除是算作一个字母的
                dp[i][j] = min([first, second, third])
            return dp[i][j]
        
        return dfs(n, m)
        
```