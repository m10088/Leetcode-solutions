[原题](https://leetcode.com/problems/flatten-nested-list-iterator/)


题意：


给定一颗树，只有每个叶子节点是含有有价值的信息的，需要设计一个迭代器。


首先应该明白迭代器使用的是栈。


但是巧妙的是，对于每个list类型的节点，应该从后面加入stack中，只要这样第一个被弹出的元素才是，最开始的。


```Python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
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
         
class NestedIterator(object):
    

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        # 首先传入的是一个list
        self.stack = nestedList[::-1]
        
    def next(self):
        """
        :rtype: int
        """
        return self.stack.pop().getInteger() if self.hasNext() else None
        
    def hasNext(self):
        """
        :rtype: bool
        """
        while len(self.stack):
            cur = self.stack[-1]
            if cur.isInteger():
                return True
            self.stack.pop()
            tmp = cur.getList()[::-1]
            self.stack.extend(tmp)
        return False
        
# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())

```