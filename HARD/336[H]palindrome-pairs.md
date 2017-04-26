[原题](https://leetcode.com/problems/palindrome-pairs)

题意

题解

```Python
class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        mp = dict()
        n = len(words)
        ret = set()
        for i in range(n): 
            mp[words[i]] = i
        
        for i in range(n):
            word = words[i]
            for k in range(len(word)+1):
                str1, str2 = word[:k], word[k:]
                # print str1, str2
                if str1[::-1]==str1 and str2[::-1] in mp:
                    if mp[str2[::-1]]!=i:
                        
                        ret.add((mp[str2[::-1]], i))
                if str2[::-1]==str2 and str1[::-1] in mp:
                    if mp[str1[::-1]]!=i:
                        
                        ret.add((i, mp[str1[::-1]]))
        return list(ret)
        
   
            
```