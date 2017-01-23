[原题](https://leetcode.com/problems/permutation-sequence/)


题意：

1-n的所有排列是一个字符串的列表。

我们需要找到第x个字符串是什么。


基本思路如下。

如果是n的序列。

待选择的序列已经存在了。

因为第一个数字是从大到小同等机会的出现，每个数字出现(n-1)!次。

因此，为了判断需要第一数字是什么。需要除以 (n-1)!，同时计算余数，

在缩小后的区间中，除掉已经找到的目标数字，递归的进行上述过程。


为了增加性能，可以改为迭代。


```Python
import math
class Solution:
    # @param {integer} n
    # @param {integer} k
    # @return {string}
    def getPermutation(self, n, k):
        numbers = range(1, n+1)
        permutation = ''
        k -= 1
        while n > 0:
            n -= 1
            # get the index of current digit
            index, k = divmod(k, math.factorial(n))
            permutation += str(numbers[index])
            # remove handled number
            numbers.remove(numbers[index])

        return permutation
```