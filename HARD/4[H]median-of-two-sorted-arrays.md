[原题](https://leetcode.com/problems/median-of-two-sorted-arrays)

题意

题解

```Python
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def findKth(nums1, nums2, k):
            m, n = len(nums1), len(nums2)
            if m > n:
                m, n = n, m
                nums1, nums2 = nums2, nums1
            if m == 0: return nums2[k-1]
            if k == 1: return min(nums1[0], nums2[0])
            i, j = min(k//2, m), min(k//2, n)
            if nums1[i-1] < nums2[j-1]:
                return findKth(nums1[i:], nums2[:], k-i)
            else:
                return findKth(nums1[:], nums2[j:], k-j)
        
        n, m = len(nums1), len(nums2)
        if (m+n) % 2 == 1:
            return findKth(nums1, nums2, (m+n+1)//2)
        else:
            return 0.5*(findKth(nums1, nums2, (m+n)//2) + findKth(nums1, nums2, (m+n+2)//2))
        
        
```