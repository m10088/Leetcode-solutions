[原题](https://leetcode.com/problems/elimination-game)

题意:

先从左向右，然后再从右向左移除数字，移除的规则是隔一个移除一个数字，求最后剩下的那个数字。

题解:

1,2,3,4,5 => 2,4 => (1,2) x 2
1,2,3,4,5,6 => 2,4,6 => (1,2,3) x 2


从左向右的时候，都会被规约为从右向左的下一步。

1,2,3,4,5 => 2,4 => (1, 2) 映射为(2,4)
1,2,3,4,5,6 => 1,3,5 => (1,2,3)映射为(1,3,5)


从右向左的时候需要分两种情况讨论。

```Python
class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        def left_to_right(n):
            return 2 * right_to_left(n//2) if n > 2 else n
        def right_to_left(n):
            if n <= 2: return 1
            if n % 2 == 1: return 2 * left_to_right(n // 2)
            return 2 * left_to_right(n // 2) - 1
        
        return left_to_right(n)
        
```