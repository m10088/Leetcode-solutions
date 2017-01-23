[原题](https://leetcode.com/problems/valid-anagram/)

题意：

一个字符串是不是另一个的乱序。

oneline

```Python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        from collections import Counter
        return Counter(s) == Counter(t)

```
