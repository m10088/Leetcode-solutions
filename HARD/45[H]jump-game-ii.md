[原题](https://leetcode.com/problems/jump-game-ii)

题意

题解

```Python
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        farest = 0
        curend = 0
        n = len(nums)
        counter = 0
        for i in range(n-1): # 在进行到每一步的时候都更新当前位置能够到达的最远的距离
            farest = max(farest, i+nums[i])
            if i==curend: # 如果当前“确实需要”跳一步了，才进行跳一步
                counter += 1
                curend = farest
        return counter

        # 这个题目也可以进行BFS，每次状态转移都是右边的元素，但是复杂度可能会很高，如果优化？
        # 正确的方式就是保存一个当前节点能够到达的一个范围
        # def jump(self, nums):
        #     n, start, end, step = len(nums), 0, 0, 0
        #     while end < n - 1:
        #         step += 1
        #         maxend = end + 1 # 如果是end那么后面的地方就不成立了
        #         for i in range(start, end + 1):
        #             if i + nums[i] >= n - 1:
        #                 return step
        #             maxend = max(maxend, i + nums[i])
        #         start, end = end + 1, maxend # 最坏的情况就是每次这个范围都向前推进一个格子
        #     return step

```