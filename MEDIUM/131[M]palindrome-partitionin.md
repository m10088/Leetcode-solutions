[原题](https://leetcode.com/problems/palindrome-partitionin)

题意:

给定一个字符串，返回所有的分割方法，这些方法应该满足让其中的每一个substring都是回文的。

题解:

简单的回溯，就是注意结束的条件的判断。

```
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        final, tmp, n = [], [], len(s)
        def dfs(b, e):
            tar = s[b:e]
            if tar == tar[::-1]:
                tmp.append(tar)
                if e == n: final.append(tmp[:])
                for i in range(e+1, n+1):
                    dfs(e, i)
                tmp.pop(-1)
        for i in range(1, n+1):
            dfs(0, i)
        return final
```


