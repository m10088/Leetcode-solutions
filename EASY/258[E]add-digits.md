[原题](https://leetcode.com/problems/add-digits/)

题意：

将一个数字，分解求和，如果这个和是一位数，返回，否则递归求解。

```Python
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        split_str = list(str(num))
        splite_num = [int(x) for x in split_str]
        if len(splite_num) == 1:
            return splite_num[0]
        else:
            return self.addDigits(sum(splite_num))
```
