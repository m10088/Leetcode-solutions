[原题](https://leetcode.com/problems/shortest-palindrome)

题意

题解

```Python
class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def get_next(t):
            nxt = [0] * len(t)
            for i in range(1, len(t)):
                j = nxt[i-1]
                while j>0 and t[i]!=t[j]: j = nxt[j-1]
                nxt[i] = j + 1 if t[i]==t[j] else j
            return nxt
        
        nxt = get_next(s + '#' + s[::-1])
        return s[::-1][:len(s)-nxt[-1]] + s

```