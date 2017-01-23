[原题](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters)

题意：

求一个最长的子串满足一个性质，就是出现次数最少的那个元素出现的次数，大于k。

题解：


分治，对于一个字符串，统计出现次数最少的那个元素，然后判断是不是出现次数大于k如果如果是，直接返回如果不是，剔除当前字符，在形成的分隔的子串中递归的进行这个过程。

```Python
class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if len(s) == 0: return 0
        hashing = set(s)
        c = min(hashing, key=lambda x:s.count(x))
        if s.count(c) >= k: return len(s)
        return max([self.longestSubstring(substr, k) for substr in s.split(c)])
```
