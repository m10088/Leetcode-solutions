[原题](https://leetcode.com/problems/lfu-cache)

题意

题解

```
def dictInsert(d, cnt, node):
        if cnt not in d:
            d[cnt] = Double()
            d[cnt].insert(node)
        else:
            d[cnt].insert(node)

class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None
        
class Double:
    def __init__(self):
        self.head = Node(-1)
        self.head.next = self.head
        self.head.prev = self.head
        self.size = 0
        
    def insert(self, node):
        
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
        node.prev = self.head
        self.size += 1

    def remove(self, node): # this node must exisit in the list
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1
    
    def gettail(self):
        return self.head.prev
    
class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.freq = dict()
        self.hashing = dict() # mapping key -> (Node, value, freq)
        self.M = capacity
        self.minFreq = 0
        
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.hashing: return -1
        
        
        
        origin_freq = self.hashing[key][2]
        node = self.hashing[key][0]
        self.freq[origin_freq].remove(node)
        dictInsert(self.freq, origin_freq+1, node)
        self.hashing[key][2] += 1
        
        if self.freq[self.minFreq].size == 0:
            self.minFreq += 1
            
        
        return self.hashing[key][1]
    
    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.M <=0: return
    
        if self.get(key) != -1:
            self.hashing[key][1] = value
            return
        
        if len(self.hashing) == self.M:
            # remove the deleter
            
            node = self.freq[self.minFreq].gettail()
            origin_freq = self.hashing[node.key][2]
            self.hashing.pop(node.key)
            self.freq[origin_freq].remove(node)
            
        # insert the new Node
        tmpNode = Node(key)
        self.hashing[key] = [tmpNode, value, 1]
        dictInsert(self.freq, 1, tmpNode)
        self.minFreq = 1
        
# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```