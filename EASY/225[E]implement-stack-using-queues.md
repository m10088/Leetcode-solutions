[原题](https://leetcode.com/problems/implement-stack-using-queues/)

题意：

使用队列模拟栈。

思路和232相同，如果想访问刚刚入队的元素，那么就应该先将这个队列中的所有元素依次出队，进入另个队列，一直到剩余一个元素为止。剩余的那个元素就是要访问的元素。然后还原这个队列的状态。

pop和top都需要在两个队列之间将元素进行两次迁移。

```Python
import Queue
class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.q1, self.q2 = [], [] 
        
    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.q1.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        if self.empty(): return None
        while len(self.q1) != 1:
            e = self.q1.pop(0)
            self.q2.append(e)
        self.q1.pop(0)
        while len(self.q2) != 0:
            e = self.q2.pop(0)
            self.q1.append(e)
        

    def top(self):
        """
        :rtype: int
        """
        if self.empty(): return None
        while len(self.q1) != 1:
            e = self.q1.pop(0)
            self.q2.append(e)
        ret = self.q1.pop(0)
        self.q2.append(ret)
        while len(self.q2) != 0:
            e = self.q2.pop(0)
            self.q1.append(e)
        return ret

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.q1) == 0
        
```

当然可以进行一个优化，就是新增一个toper的变量记录当前的toper，那么top就能优化到O(1)，toper的更新是在pop的时候更新的。


