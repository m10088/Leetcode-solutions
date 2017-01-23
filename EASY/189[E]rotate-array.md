[原题](https://leetcode.com/problems/rotate-array/)


题意：

旋转一个数组，For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]


首先naive的做法，就不说了，另外开一个数组，然后，两次复制。

但是题目要求是空间复杂度O（1）。

因此想到，一步一步的挪动，需要挪动k步。

```Python
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def make_one_round(li):
            if len(li) <= 1:
                return
            piv = li[-1]
            for i in range(1, len(li)):
                li[-i] = li[-(i+1)]
            li[0] = piv
        
        for _ in range(k):
            make_one_round(nums)
```

超时了算法复杂度是square级别的，当然，这里可以优化，就是，根据k的位置，考虑向左向右移动，但是本质上没有改变，算法的复杂度，因此，不考虑这种方法。


一种神奇的解法。


很神奇一共有3步。假设输入数组的下标是0~ n-1，需要rotate的步数是k.
step 1 reverse原来的数组
step 2 reverse 0~ k-1
step 3 reverse k ~ n-1

```Python
class Solution(object):
    def rotate(self, li, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def reverse(li, begin, end):
            if end <= begin:return
            while begin < end:
                li[begin], li[end] = li[end], li[begin]
                begin += 1
                end -= 1
            
        n = len(li)
        if n <= 1:return
        k = k % n
        reverse(li, 0, n-1)
        reverse(li, 0, k-1)
        reverse(li, k, n-1)
```
