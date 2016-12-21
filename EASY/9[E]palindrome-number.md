[原题](https://leetcode.com/problems/palindrome-number/)

题意：

判断一个数是不是回文数。

```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        return str(x)[::-1] == str(x)
```
