[原题](https://leetcode.com/problems/anagrams/)

题意：

将乱序的字母组成的数字，分好类。

hash即可。

首先python的set不能当作hash的对象。
齐次，这里使用set也是错的，因为一个字母可能出现了多次。

解法：

将单词排序即可。然后hash即可。

```
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        sorted_to_list = {}
        for s in strs:
            sorted_string = ''.join(sorted(s))
            if sorted_string not in sorted_to_list:
                sorted_to_list[sorted_string] = []
            sorted_to_list[sorted_string].append(s)
        
        return [value for key,value in sorted_to_list.items()]

```