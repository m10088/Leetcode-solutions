[原题](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

题意：

找一个字符串s中的p的乱序字串的开始的index。


滑动窗口的同时维护一个hash表即可。

python的hash表支持==操作。

注意在维护的过程中，某个hash的值变为0，要及时的删除。

```
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        
        if len(p) > len(s) : return []
        from collections import Counter
        pcnt = collections.Counter(p)
        scnt = collections.Counter(s[:len(p)])
        ret = []
        if pcnt == scnt: ret.append(0)
        for i in range(len(p), len(s)):
            char_to_add = s[i]
            char_to_remove = s[i-len(p)]
            scnt[char_to_add] = 1 if char_to_add not in scnt else scnt[char_to_add] + 1
            scnt[char_to_remove] -= 1
            if scnt[char_to_remove] == 0: del scnt[char_to_remove]
            
            if scnt == pcnt:
                ret.append(i-len(p)+1)
        return ret
```