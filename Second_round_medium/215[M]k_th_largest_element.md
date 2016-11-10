[原题](https://leetcode.com/problems/kth-largest-element-in-an-array/)

题意：

数组中，k大的元素。

使用优先队列解法。

```
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        from Queue import PriorityQueue
        pq = PriorityQueue()
        for item in nums: pq.put((-item, item))
        cnt, res = 0, -1
        while cnt < k: 
            res = pq.get()[1]
            cnt += 1
        return res
```

使用快速排序中的划分的解法。

```
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def partation(a, lo, hi):
            """a - is a list """
            if lo == hi: return lo
            piv = a[lo]
            i = lo
            for j in range(lo+1, hi+1):
                if a[j] < piv: pass
                else:
                    i += 1
                    a[i], a[j] = a[j], a[i]
            a[lo], a[i] = a[i], a[lo]
            return i
            
            
        
        # But i will just use partation-method here
        
        def select(nums, lo, hi, k):
            piv = partation(nums, lo, hi)
            if k == piv-lo+1: return nums[piv]
            elif k < piv-lo+1: return select(nums, lo, piv-1, k)
            else: return select(nums, piv+1, hi, k-(piv-lo+1))
        return select(nums, 0, len(nums) - 1, k)
        
        
        
```

[ref](https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively)
