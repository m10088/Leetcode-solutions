[原题](https://leetcode.com/problems/counting-bits/)

题意：

给一个数字n，给出从0-n之间的所有数字的某个性质，这个性质是转化成二进制后，1的个数。

每次将数组扩大一倍，扩大一倍的时候，相当于在原来的对应位置的基础上进行了+1操作。

```
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0]
        times = 0
        while 2 ** times <= num:
            # each time the size of res expand 2 times
            n = len(res)
            for i in range(n):
                res.append(res[i] + 1)
            times += 1
        return res[:num + 1]
```