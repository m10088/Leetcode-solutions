[原题](https://leetcode.com/problems/peeking-iterator/)


题意：


实现一个序列的next和hasnext的函数，主要就是在每次next调用之后，以及初始化的时候，提前将下一个数字保存好。


```Python
class PeekingIterator(object):
    def __init__(self, iterator):
        self.iter = iterator
        self.temp = self.iter.next() if self.iter.hasNext() else None

    def peek(self):
        return self.temp

    def next(self):
        ret = self.temp
        self.temp = self.iter.next() if self.iter.hasNext() else None
        return ret

    def hasNext(self):
        return self.temp is not None
```