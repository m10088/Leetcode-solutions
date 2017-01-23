[原题](https://leetcode.com/problems/merge-sorted-array/)

题意：

给定一个数组大小是（m+n）其中前m个数字是升序的，后n个数字位置为空。另外给定一个大小是n的数组，数字都是升序的，在不使用额外的空间的条件下，将2数组合并到1数组。


正常思路是需要用到额外的空间的，但是如果从后面开始，这个问题就迎刃而解。

```Python
class Solution(object):
    def merge(self, nums1, m, nums2, n):
    	"""
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        i = m-1
        j = n-1
        k = m+n-1
        
        while(i >= 0 and j >= 0):
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                k -= 1
                i -= 1
            else:
                nums1[k] = nums2[j]
                k -= 1
                j -= 1
        while(j >= 0):
            nums1[k] = nums2[j]
            k -= 1
            j -= 1
```

