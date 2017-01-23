[原题](https://leetcode.com/problems/132-pattern)

题意:

在一个序列中，找看看有没有类似132这种大小关系的序列。

首先容易想到的是O(n^2)级别的算法。

就是每次选择一个第i个数字，首先找到左边的最小的，然后再从右边找有没有符合题意的。

这种方法，显然不是最优的，而且题目的tag是stack，最后评论区有人给出了one pass的解法，很优雅。但是实在是很难想到。

题解:


```Python
class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums = nums[::-1]
        second_max, n, stack = float('-inf'), len(nums), []
        for num in nums:
            if num < second_max: return True
            else:
                while len(stack) != 0 and num > stack[-1]:
                    second_max = stack[-1]
                    stack.pop(-1)
                
                stack.append(num)
        return False

```

基本思路是从后面往前遍历，并同时维护一个单调栈，并且保存上一次出栈过程中的最大值。

那么新的最大值，就相当与132种的3，上一次出栈过程中的最大值，就是在3后面的2，每次迭代过程的最开始我们要判断一下那个1是不是存在。
