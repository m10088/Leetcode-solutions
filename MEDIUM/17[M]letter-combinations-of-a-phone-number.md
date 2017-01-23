[原题](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

题意：

给出数字的一些按键，给出所有的按键的可能组成字母的方式。

给出一种很巧妙的reduce的解决方法。


```Python
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if '' == digits: return []
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        # acc -> already ok list
        return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])
```