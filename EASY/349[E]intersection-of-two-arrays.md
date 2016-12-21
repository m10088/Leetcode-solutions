[原题](https://leetcode.com/problems/intersection-of-two-arrays/)

题意：

找两个数组的公共的部分，结果不能重复。


一行代码解决

```
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
       
        return list(set([x for x in nums1 if x in nums2]))
        
```