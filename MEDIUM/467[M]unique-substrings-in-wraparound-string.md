[原题](https://leetcode.com/problems/unique-substrings-in-wraparound-string)

题意:

s是一个无限的字符串"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...."

给定p，判断有多少个独一无二的子串满足一个性质——这个子串在s中。


```
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
```

题解:

一共26个字母，只要记录以字母x结尾的最长的规范子串的长度（规范子串就是在s中的子串）。

这里有个问题，就是如果有个是这样的呢？

abcd.....zabcd，假如是d，那么我们应该记录的是5，而不是4，也就是那个大的，而且不能重复记录，因为只要记录了5，就包括了 "zabcd","abcd","bcd","cd","d" 也就包含了那些小的了。

```
class Solution(object):
    def findSubstringInWraproundString(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, Len = len(s), dict()
        for char in 'abcdefghijklmnopqrstuvwxyz': Len[char] = 0
        curLen = 0
        
        for i in range(n):
            if i > 0 and ord(s[i])-97 == (ord(s[i-1])-97 + 1) % 26:
                curLen += 1
            else:
                curLen = 1
            
            Len[s[i]] = max(Len[s[i]], curLen)
        
        return sum([value for key, value in Len.items()])
```

