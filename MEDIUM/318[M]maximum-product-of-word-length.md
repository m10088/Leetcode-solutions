[原题](https://leetcode.com/problems/maximum-product-of-word-length)

题意:

Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

因为这两个单词中的字母没有任何交集。

题解:

```Python
class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        mmax, n, st = 0, len(words), []
        for word in words:
            st.append((len(word), set(list(word))))
        # 直接使用python内建的intersection函数
        for i in range(n):
            for j in range(i):
                if not st[i][1].intersection(st[j][1]):
                    mmax = max(mmax, st[i][0] * st[j][0])
        return mmax
```
