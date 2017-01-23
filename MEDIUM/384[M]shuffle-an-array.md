[原题](https://leetcode.com/problems/shuffle-an-array/)

题意：

随机算法：打乱一个数组。

每个数字，按照相同的概率和自身以及前面的数字进行交换。


证明过程，详见算法导论。


```Python
class Solution(object):

    def __init__(self, nums):
        """
        
        :type nums: List[int]
        :type size: int
        """
        self.origin = nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.origin
        
    # need prove that

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        ret = self.origin[:]
        n = len(ret)
        for i in range(0, n):
            sel = random.randint(0, i)
            
            ret[sel], ret[i] = ret[i], ret[sel]
        return ret
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
```