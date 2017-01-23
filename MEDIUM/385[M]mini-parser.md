[原题](https://leetcode.com/problems/mini-parser)

题意:

解析一个序列成为一个类似语法分析树的东西，简单的递归子程序法（LL分析），如果学过编译原理，那么这道题目就不是问题。

题解:

```Python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#       
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution(object):
    def __init__(self):
        self.cur = 0
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        n = len(s)
        
        def isDigit(char):
            return char in '0123456789'
        
        def getNumber():
            """返回一个Number的对象"""
            flag, res = 1, 0
            if s[self.cur] == '-': flag, self.cur = -1, self.cur + 1
            while self.cur != n and isDigit(s[self.cur]):
                res, self.cur = res * 10 + int(s[self.cur]), self.cur + 1
            return NestedInteger(res*flag)
        
        def getList():
            """返回一个List的对象"""
            assert s[self.cur] == '['
            self.cur, res = self.cur + 1, NestedInteger()
            # 这里先判断一下是不是空的
            if s[self.cur] == ']':
                self.cur += 1
                return NestedInteger()
            
            while True:
                if s[self.cur] == '-' or isDigit(s[self.cur]):
                    obj = getNumber()
                    res.add(obj)
                else:
                    obj = getList()
                    res.add(obj)
                
                if s[self.cur] == ',': self.cur += 1
                else: # right-bracket ']'
                    self.cur += 1
                    break
            return res
            
        assert s != ''
        
        if s[0] == '[': return getList()
        else: return getNumber()
        
```
