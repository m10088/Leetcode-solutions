[原题](https://leetcode.com/problems/reverse-vowels-of-a-string/)

题意：

将一个字符串中的元音字母，反转，之后在放进去。

python的str类型，居然不能赋值。

str[0] = 'a'

error

```
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        temp = []
        vowel = 'aeoiuAEIOU'
        for i, char in enumerate(s):
            if char in vowel:
                temp.append([i, char])
        for i in range(0, len(temp)//2):
            j = len(temp) - i - 1
            temp[i][1], temp[j][1] = temp[j][1], temp[i][1]
        s = list(s)
        for i, char in temp: s[i] = char
        return ''.join(s)
        
        
```
