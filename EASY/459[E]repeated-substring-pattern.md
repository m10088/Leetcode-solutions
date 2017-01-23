[原题](https://leetcode.com/problems/repeated-substring-pattern/)


题意：


找到字符串是不是由某个字符串重复产生的。

暴力枚举即可。


```Python
class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type str: str
        :rtype: bool
        """
        n = len(s)
        # try different length
        for i in range(1, n // 2 + 1):
            if n % i !=0 : continue
            # check if all equal
            ok = True
            for offset in range(0, i):
                checker = set()
                for j in range(offset, n, i):
                    checker.add(s[j])
                if len(checker) != 1:
                    ok = False
                    break
            if ok: return True
        return False
            
```