[原题](https://leetcode.com/problems/happy-number/)

题意：

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

递归的进行，看看能不能将一个数字变成1？

小于10的数字，如果不是1就一定失败吗？
如果是7,49,97,130，10发现是成功的，特判即可？
**为什么不检验大于10的？**
因为这个过程是一个圈的，在转圈的过程中，一定有一个状态是小于10的。其他状态都和小于10的那个状态等价。

```
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        tmp_sum = sum([int(x)*int(x) for x in str(n)])
        if tmp_sum < 10:
            return tmp_sum == 1 or tmp_sum == 7
        else:
            return self.isHappy(tmp_sum)
```