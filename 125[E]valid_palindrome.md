[原题](https://leetcode.com/problems/valid-palindrome/)

题意：

判断是不是回文数。数字和字母，其他忽略。


```
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def f(x):
            if ord('a') <= ord(x) <= ord('z') or ord('0') <= ord(x) <= ord('9'):
                return x
            if ord('A') <= ord(x) <= ord('Z'):
                return chr(ord(x) + 32)
            else:
                return ''
        s = ''.join(map(f, s))
        
        return s[::-1] == s
        
```