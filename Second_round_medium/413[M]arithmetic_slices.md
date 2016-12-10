[原题](https://leetcode.com/problems/arithmetic-slices/)

题意：

寻找三个连续的数字组成等差数列的组数有多少组。

首先找到连续的数字组成等差数列的情况，如果连续的等差数列是n，那么根据简单的公式就能求出三等差数列的个数。

```
class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        tmpRes = []
        i, n = 0, len(A)
        tmpCnt = 0
        while i < n-2:
            if A[i+2] - A[i+1] == A[i+1] - A[i]:
                tmpCnt += 1
            else:
                tmpRes.append(tmpCnt)
                tmpCnt = 0
            i += 1
        if tmpCnt != 0:
            tmpRes.append(tmpCnt)
    
        return sum([(x*(x+1)/2) for x in tmpRes])
```