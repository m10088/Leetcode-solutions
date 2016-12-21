[原题](https://leetcode.com/problems/increasing-triplet-subsequence/)

题意：

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.


想到的方法是，首先从左到右扫描一遍，找到截至扫描到的数字为止的最小的值是多少记录到一个数组中，从右边向左边扫描一遍，记录戒指目前为止，扫描到的数字为止，扫描到的最大的数字是多少。

最后进行最后一遍扫描，判断所有的数字是不是符合题意。

这种方法，进行了三次扫描显然不是很合适。

但是我们可以在一次扫描的过程中，不断的记录最小的值和次小的值，看是否能发生更新，如果本次不能发生更新，那么说明能够找到这样的值。

```

class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        c1, c2 = float('inf'), float('inf')
        for num in nums:
            if num <= c1:
                c1 = num
            elif num <= c2:
                c2 = num
            else:
                return True
        
        return False
```