[原题](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed)

题意

题解

```
class RandomizedCollection(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.mmp = dict()
        self.vec = []

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        flag = False
        if val not in self.mmp:
            self.mmp[val] = [len(self.vec)]
            flag = True
        else:
            self.mmp[val] += [len(self.vec)]
        self.vec.append(val)
        
        #print self.mmp
        #print self.vec
        
        return flag
        
    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        contain = False
        if val in self.mmp: contain = True
        if contain:
            # 如果存在，那么删除其中的一个元素
            idx = self.mmp[val][0]
            # 如果就是最后一个元素，直接删除
            if idx == len(self.vec) - 1:
                self.vec.pop(-1)
                self.mmp[val].remove(idx)
            else:
                # 如果不是最后一个元素，先和最后一个元素交换
                last_idx, last_elem = len(self.vec) - 1, self.vec[-1]
                self.mmp[last_elem].remove(last_idx)
                self.mmp[last_elem].append(idx)
                self.vec[idx] = last_elem
                self.vec.pop(-1)
                self.mmp[val].remove(idx)
            
            if self.mmp[val] == []:
                self.mmp.pop(val)
        #print val, 'ok'
        #print self.mmp
        #print self.vec
        return contain
                
    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        return self.vec[random.randint(0, len(self.vec)-1)]


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```