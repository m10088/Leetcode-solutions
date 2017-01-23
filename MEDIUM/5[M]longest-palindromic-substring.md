[原题](https://leetcode.com/problems/longest-palindromic-substring)

题意:

找到一个字符串中，最长的回文字符串。


题解:


其实也没有什么trick，就是暴力，而已。


首先可以尝试一种方法：

对于每个i位置，分别假设奇数的长度和偶数的长度，向两边更新，早晚更新到不能更新为止。记录下长度和开始的位置。看看能不能更新结果。


评论区发现的一种有趣的解法：

```Python
class Solution:
    # @return a string
    def longestPalindrome(self, s):
        if len(s)==0:
            return 0
        maxLen=1
        start=0
        for i in xrange(len(s)):
            if i-maxLen >=1 and s[i-maxLen-1:i+1]==s[i-maxLen-1:i+1][::-1]:
                start=i-maxLen-1
                maxLen+=2
                continue

            if i-maxLen >=0 and s[i-maxLen:i+1]==s[i-maxLen:i+1][::-1]:
                start=i-maxLen
                maxLen+=1
        return s[start:start+maxLen]
```

对于每个位置，检查是不是有可以更新长度，注意这里的检查范围就是增加1或者2而已。

为什么检查1或者2呢？

因为这分别是考虑了，字符串的长度是奇数，或者是偶数的情况。


