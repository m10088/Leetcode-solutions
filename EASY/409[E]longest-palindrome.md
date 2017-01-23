[原题](https://leetcode.com/problems/longest-palindrome/)

题意：

给定一些，字符，求能够构成的最长的回文串有多长。

统计每个字符的出现次数，偶数全加上，奇数少用一个，最后如果有奇数出现，中间还能多用一个。

```Python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        counter = dict()
        for char in s:
            if char not in counter:
                counter[char] = 1
            else:
                counter[char] += 1
        has_odd = 0
        even_num = 0
        
        for value, n in counter.items():
            if n % 2 == 1:
                has_odd = 1
                even_num = even_num + (n - 1)
            else:
                even_num += n
        return has_odd + even_num
    
        
            
```