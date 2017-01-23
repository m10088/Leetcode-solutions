[原题](https://leetcode.com/problems/ransom-note/)

题意：

看一下使用杂志中的单词能不能组成目标单词。


分析：

统计出现的次数即可。

```Python
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        from collections import Counter
        counter = collections.Counter(magazine)
        for char in ransomNote:
            counter[char] -= 1
            if counter[char] < 0:
                return False
        return True
```