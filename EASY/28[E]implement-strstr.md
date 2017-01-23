[原题](https://leetcode.com/problems/implement-strstr/)

题意：

字符串匹配：

暴力，即可，当然更好的是kmp匹配，这里暂时不考虑。

```Python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        
        end = len(haystack) - len(needle)
        if end < 0: return -1
        for i in range(0, end + 1):
            print haystack[i:i + len(needle)]
            if haystack[i:i + len(needle)] == needle:
                return i
        return -1
```

还是贴上kmp的解法吧。

```Python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """

        def _prefix(sub):
            """Create prefix table for substring aka needle."""
            f = [0] * len(sub)
            for i in xrange(1, len(sub)):
                k = f[i - 1]
                while k > 0 and sub[k] != sub[i]:
                    k = f[k - 1]
                if sub[i] == sub[k]:
                    k += 1
                f[i] = k
            return f

        if not haystack and not needle:
            return 0

        if haystack and not needle:
            return 0

        if len(needle) > len(haystack):
            return -1

        f = _prefix(needle)
        k = 0
        for i in xrange(len(haystack)):
            while k > 0 and haystack[i] != needle[k]:
                k = f[k - 1]
            if haystack[i] == needle[k]:
                k += 1
            if k == len(needle):
                return i - len(needle) + 1
        return -1
```