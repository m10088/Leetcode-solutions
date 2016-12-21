[原题](https://leetcode.com/problems/find-the-difference/)

题意：

s，t两个串，t串有个字母比s出现了一次，找出来。

常规解法：
统计26个字母的出现次数，t串种一定有一个出现的次数多1。

```
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        counter_s = [0] * 26
        counter_t = [0] * 26
        for char in s:
            counter_s[ord(char)-ord('a')] += 1
        for char in t:
            counter_t[ord(char)-ord('a')] += 1
        for i in range(0, 26):
            if counter_s[i] < counter_t[i]:
                return chr(97 + i)
                
```


但是这里有另一种解法：
如果将s和t的字符混合的话，那么要找的那个数字，一定出现了奇数次，其他的数字，出现了偶数次，因此可以使用异或。

```
def findTheDifference(self, s, t):
    """
    :type s: str
    :type t: str
    :rtype: str
    """
    ans = 0
    for c in s + t:
        ans ^= ord(c)
    return chr(ans)
```

