[原题](https://leetcode.com/problems/insert-delete-getrandom-o1)

题意：

题解：

```
import random
class RandomizedSet(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        
        self.index = dict()
        self.element = []
        
    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.index: 
           return False
        
        idx = len(self.element)
        self.index[val] = idx
        self.element.append(val)
        
        return True
        
    
    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.index: return False
      
        last = self.element[-1]
        # 将最后一个元素放到目标的位置，更新
        self.index[last] = self.index[val]
        self.element[self.index[val]] = last
        self.element.pop(-1)
        self.index.pop(val)
        
        return True
            
        
    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        n = len(self.element)
        assert n >= 1
        return self.element[random.randint(0, n-1)]
        
        
        
# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```