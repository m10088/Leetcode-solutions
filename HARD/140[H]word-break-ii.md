[原题](https://leetcode.com/problems/word-break-ii)

题意

题解

```Python
# 呵呵最后一个样例的出现完全就是为了恶心玩家吗？
# 采纳了discuss一个朋友的建议，为了过最后一个样例先跑一边WordBreakI，如果可以进行分割，然后才继续
# 挺蠢的

class Solution(object):
    
    def wordBreakTest(self, s, wordDict):
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
    
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        if not self.wordBreakTest(s, wordDict): return []
        n = len(s)
        ret = []
        wordDict = set(wordDict)
        def dfs(cur, tmpList):
            if cur == n:
                ret.append(tmpList[:])
                return
            for i in range(cur+1, n+1):
                word = s[cur:i]
                if word in wordDict:
                    tmpList.append(word)
                    dfs(i, tmpList)
                    tmpList.pop(-1)
        tmpList = []
        dfs(0, tmpList)
        
        return [' '.join(x) for x in ret]
        
                
```