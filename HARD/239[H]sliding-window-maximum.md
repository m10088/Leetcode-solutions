[原题](https://leetcode.com/problems/sliding-window-maximum)

题意

题解

```
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k < 2: return nums
        ret = []
        q = []
        for i in range(k):
            while len(q) > 0 and nums[q[-1]] <= nums[i]:
                q.pop(-1)
            q.append(i)
        # 先将开始的部分元素全部放放进
        ret.append(nums[q[0]])
        
        for i in range(k, len(nums)):
            # 判断开头的元素需要remove掉吗？
            if i-q[0] >= k:
                q.pop(0)

            while len(q) > 0 and nums[q[-1]] <= nums[i]:
                q.pop(-1)
                
            q.append(i)
            ret.append(nums[q[0]])
            
        return ret
        
        # 提供另一种解决思路：
        # 使用C++ map存放map[(value, index)] = index。
        # 其中那个key需要定义一种排序方式，就是首先按照value从大到小排序，index无所谓。
        # 这个map维护的是某个时刻的k个数字，然后最大值就是map迭代器开始位置。
        # 然后每次迭代开始的时候，都要把距离最远的那个元素从map中erase掉。然后插入新的元素，然后进行找最大值（迭代器开始的位置）
        # 上述算法的复杂度是O(nlgn)
        
            
```