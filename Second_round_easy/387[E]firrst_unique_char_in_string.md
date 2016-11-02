[原题](https://leetcode.com/problems/first-unique-character-in-a-string/)

题意：

找第一个在串中unique的字符。

```
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        counter = dict()
        for char in s:
            if char not in counter:
                counter[char] = 1
            else:
                counter[char] += 1
        for i in range(0, len(s)):
            if counter[s[i]] == 1:
                return i
        return -1
```
