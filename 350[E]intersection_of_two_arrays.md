[原题](https://leetcode.com/problems/intersection-of-two-arrays-ii/)


题意：

两个数组的交集。考虑重复的元素。

需要统计元素出现的次数。

hash即可。

```
class Solution(object):
  
    def intersect(self, nums1, nums2):  
        """ 
        :type nums1: List[int] 
        :type nums2: List[int] 
        :rtype: List[int] 
        """  
        cnt = collections.Counter(nums1)  
        ans = []  
        for val in nums2:  
            if cnt.has_key(val) and cnt[val]>0:  
                ans.append(val)  
                cnt[val]-=1  
        return ans 
```

如果是有序的，贪心的merge即可。


- What if nums1's size is small compared to nums2's size? Which algorithm is better?
- What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

- 两个算法的复杂度都是O(m+n)，数组大小无影响。
- 如果nums2在磁盘中, 用hash表无影响。
- 