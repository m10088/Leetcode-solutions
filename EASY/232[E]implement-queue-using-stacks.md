[原题](https://leetcode.com/problems/implement-queue-using-stacks/)

题意：使用两个栈实现队列。


主要是出队的时候，需要访问栈底的元素，因此需要另外一个栈进行倒入然后倒出。


```Python
class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []
        
    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.stack1.append(x)
        
    def pop(self):
        """
        :rtype: nothing
        """
        if len(self.stack1) == 0: return
    
        while len(self.stack1) != 0:
            e = self.stack1.pop()
            self.stack2.append(e)
        self.stack2.pop()
        while len(self.stack2) != 0:
            e = self.stack2.pop()
            self.stack1.append(e)
        
    def peek(self):
        """
        :rtype: int
        """
        while len(self.stack1) != 0:
            e = self.stack1.pop()
            self.stack2.append(e)
        ret = self.stack2[-1]
        while len(self.stack2) != 0:
            e = self.stack2.pop()
            self.stack1.append(e)
        return ret

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.stack1) == 0
        
```


考虑到peek和pop都需要O(n)的复杂度，实际上是仍然能够进行优化的，保存一个peeker的变量，只有在pop的时候对这个元素进行更新。查询peek()的时候就是O(1)的复杂度了。

