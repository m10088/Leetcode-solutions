[原题](https://leetcode.com/problems/repeated-dna-sequences/)

题意：

给定一个dna串，统计串中，所有的连续的长度是10的出现次数多于一次的dns链有哪些？

首先想到的解决方案就是hash，但是一个好的hash函数是关键的，

可以采用这种hash方式，10个字母，因为一共有4种组合，ACGT，可以每个字母采用两个二进制数字进行编码，这样一共使用20位进行编码，同时字符串的滑动，可以采用int的移位函数>>解决。



但是令人兴奋的是，python内置的hash函数就很好了，不用我们进行额外的操作于是，就有了下面及其简单的代码。



```Python


class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        r, record = set(), set()
        for i in xrange(len(s) - 9):
            substring = s[i:i + 10]
            [record, r][substring in record].add(substring)
        return list(r)
        
        
        
                
                
```