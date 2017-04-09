[原题](https://leetcode.com/problems/lru-cache)

题意

题解

```
class Node(object):
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.pre = None
        self.next = None


class LRUCache(object):
    
    
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.mmax = capacity
        self.curlen = 0
        self.head = Node(-100, -100)
        self.head.next = self.head
        self.head.pre = self.head
        self.mmp = dict()
        
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.mmp: return -1
        self.deletNode(self.mmp[key])
        self.insertNode(self.mmp[key])
        return self.mmp[key].val
        
    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        # 如果是已经存在的数据了
        if key in self.mmp:
            self.mmp[key].val = value
            self.get(key)
            return
        
        tmpNode = Node(key, value)
        self.mmp[key] = tmpNode
        
        if self.curlen < self.mmax: # 数据还没有装满，直接装上
            self.insertNode(tmpNode)
        else:
            # 删除链表尾部的节点，然后插入一个头部节点
            tail, tailkey = self.head.pre, self.head.pre.key
            self.deletNode(tail)
            self.mmp.pop(tailkey)
            self.insertNode(tmpNode)
    
    def deletNode(self, tmpNode):
        tmpNode.pre.next = tmpNode.next
        tmpNode.next.pre = tmpNode.pre
        self.curlen -= 1
    
    def insertNode(self, tmpNode): # 头部插入
        # 插在链表的头部
        tmpNode.next = self.head.next
        tmpNode.pre = self.head
        self.head.next.pre = tmpNode
        self.head.next = tmpNode
        self.curlen += 1

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```