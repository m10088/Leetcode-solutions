[原题](https://leetcode.com/problems/reverse-words-in-a-string/)

题意：

反转字符串中的单词，类似。

```
Given s = "the sky is blue",
return "blue is sky the".
```

python的解法.

```Python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        import re
        if not s: return s
        slist = re.split(r'\s+', s.strip())
        words = slist[::-1]
        ret = ''
        for word in words: ret += word + ' '
        return ret.strip()
```

还有原地的解法(C++).

先将字符串整个的反转然后，每个单词进行反转。


```C++
void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int storeIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (storeIndex != 0) s[storeIndex++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
            reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
            i = j;
        }
    }
    s.erase(s.begin() + storeIndex, s.end());
}
```
