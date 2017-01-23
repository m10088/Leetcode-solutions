[原题](https://leetcode.com/problems/4sum-ii/)


题意：

在4个数组中，分别找4个数字让他们的和是0，这里返回的是索引，因此不会产生重复，简单的题目，看代码。


```Python
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        n = len(A)
        mp, res = dict(), 0
        
        for i in range(n):
            for j in range(n):
                s = A[i] + B[j]
                if s not in mp: mp[s] = 1
                else: mp[s]+=1
        
        for i in range(n):
            for j in range(n):
                target = -(C[i] + D[j])
                if target not in mp: continue
                res += mp[target]
        return res
```