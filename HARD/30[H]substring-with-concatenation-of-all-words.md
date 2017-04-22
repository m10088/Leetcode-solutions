[原题](https://leetcode.com/problems/substring-with-concatenation-of-all-words)

题意

题解

```Python
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        # 暴力求解
        if not words: return []
        k, m = len(words[0]), len(words)
        n, ret = len(s), []
        from collections import Counter
        mmp = Counter(words)
        tmpMp = dict()
        for i in range(0, n-k*m+1):
            tmpMp.clear()
            cnt = 0
            while cnt < m:
                # 这里一开始的时候是有个判断是不是在mmp中的代码TLE，去掉之后AC。
                word = s[i+(cnt*k):i+(cnt+1)*k]
                if word not in tmpMp: tmpMp[word] = 1
                else:                 tmpMp[word] += 1
                if tmpMp[word] > mmp[word]:
                    break
                cnt += 1
            if cnt == m:
                ret.append(i)
        return ret
        
                
```