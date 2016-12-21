[原题](https://leetcode.com/problems/min-stack/)

题意：

设计一个数据结构模拟一个栈，这个栈提供的额外的功能就是在任何状态下，能够查看最小的值。

思路：

原来的思路是使用C++的multiset，和一个stack，然后查询的时候，min的时间从set查询，top的时候O(1)，从stack查询，push，和pop维护stack和set即可。

但是python不提供multiset的数据结构，如果dict统计次数，dict是hash设计的，没有顺序。

最后看了discuss上的一个解答，非常完美。

tuple保存栈的状态，分别是(self_value, min_value)，这样状态就是唯一的了。

```
class MinStack(object):

    def __init__(self):
        self.q = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        curMin = self.getMin()
        if curMin == None or x < curMin:
            curMin = x
        self.q.append((x, curMin));
    
    # @return nothing
    def pop(self):
        self.q.pop()
    
    
    # @return an integer
    def top(self):
        if len(self.q) == 0:
            return None
        else:
            return self.q[-1][0]
    
    
    # @return an integer
    def getMin(self):
        if len(self.q) == 0:
            return None
        else:
            return self.q[-1][1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```

