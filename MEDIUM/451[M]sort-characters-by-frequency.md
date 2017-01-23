[原题](https://leetcode.com/problems/sort-characters-by-frequency)

题意:

字符串，按照单词出现的频率，进行重新排序。


题解:

```Python
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 比较简单，重点还是Python的语法吧，如何对dict按照key和vaule进行排序。
        from collections import Counter
        d = collections.Counter(list(s))
        d = sorted(d.iteritems(), key=lambda x: x[1], reverse=True)
        return ''.join([x * y for x, y in d]) 
```

