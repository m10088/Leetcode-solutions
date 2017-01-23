[原题](https://leetcode.com/problems/nim-game/)

题意：

最简单的尼姆博弈。

题解：

```Python
class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n % 4 != 0
        
```