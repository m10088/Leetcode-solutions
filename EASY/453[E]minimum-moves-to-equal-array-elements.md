[原题](https://leetcode.com/problems/minimum-moves-to-equal-array-elements)

题意:

一个数组，每次操作n-1个数字，每个数字+1，然后判断一共需要操作多少次，才能让所有的数字相同。


题解:

正着考虑很麻烦，逆向思维很重要。

```Python
class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 因为题目要求最后的元素值相同即可，所以所有元素加一操作完全可以去掉，即每一次的“移动”操作等价于把最大元素减一
        return sum(nums)-min(nums)*len(nums)
        
```

