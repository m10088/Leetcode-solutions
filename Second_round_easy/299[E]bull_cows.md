[原题](https://leetcode.com/problems/bulls-and-cows/)

题意：

给定一个原始的串，和一个猜的串，如果猜的串的位置和字符完全相同，那么就是bull，如果仅仅是猜对了，位置不同那么就是cow。
输出bull和cow的个数。


先排除bull不考虑，然后根据字符出现的次数，统计cow。

```
class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        s, g = '', ''
        A, B = 0, 0
        for i in range(len(guess)):
            if secret[i] == guess[i]: A += 1
            else:
                s+=secret[i]
                g+=guess[i]
        import collections
        counter = collections.Counter
        CounterA = counter(s)
        CounterB = counter(g)
        for char in set(g):
            if char not in CounterA:
                pass
            else:
                B += min(CounterA[char], CounterB[char])
        return str(A) + 'A' + str(B) + 'B'
```