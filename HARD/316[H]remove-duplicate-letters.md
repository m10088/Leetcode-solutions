[原题](https://leetcode.com/problems/remove-duplicate-letters)

题意

题解

```Python
class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s: return ''
        from collections import Counter
        counter = Counter(s)
        pos = 0
        for i in range(len(s)):
            if s[i]<s[pos]: pos = i
            counter[s[i]] -= 1
            if counter[s[i]] == 0: break
        # 在第找到一个消失的字符之前，找到那个ascii码最小的字母，然后再后面递归进行
        return s[pos] + self.removeDuplicateLetters(s[pos+1:].replace(s[pos], ''))
```