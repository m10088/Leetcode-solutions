[原题](https://leetcode.com/problems/longest-repeating-character-replacement)

题意:

给定一个字符串，允许将k个字母替换成一个特定的字母。目的是使出现一个最长的重复字母的字串。


题解:

这个题目，我没想出来，参考的评论区，解法很巧妙，滑动窗口。

维护一个窗口，满足一个性质，出现次数最多的那个字母出现的次数是x，窗口的当前长度的是l，只要 l <= x + k，窗口就能进一步扩展。


```Python
class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if not s: return 0
        map = dict()
        # init
        for char in string.uppercase:
            map[char] = 0
        
        def getmost():
            mmax = -1
            for key, value in map.items():
                mmax = max(mmax, value)
            return mmax
        def can_extend():
            return r - l + 1 - getmost() <= k
        
        l, r, ret, n = 0, 0, 0, len(s)
        map[s[0]] = 1
        
        while l <= r:
            # print l, r
            
            if can_extend():
                ret = max(ret, r-l+1)
                r += 1
                if r == n: break
                map[s[r]] += 1
            else:
                map[s[l]] -= 1
                l += 1
        
        return ret
```