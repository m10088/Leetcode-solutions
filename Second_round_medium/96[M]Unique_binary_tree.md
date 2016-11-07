[原题](https://leetcode.com/problems/unique-binary-search-trees/)



给一个n，求能够组成的二叉搜索树，有多少种？

题解：

卡特兰数：

```
f（n）=f（0）f（n-1）+f（1）f（n-2）+……+f（n-1）f（0）
```

考虑，我们现在正在构造有n个数的BST，那么可以选择1-n之间的任意一个数字作为定点，每当选择一个定点，左右子树就自然的递归。


卡特兰数可以递推，当然可以直接给出通项公式。
```
f（n）=h（n）= C（2n,n）/（n+1）= c（2n,n）-c（2n,n+1）（n=0，1，2，……）。
最后，令f（0）=1，f（1）=1。
```

```
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        def c(n,k):  
            return  reduce(operator.mul, range(n - k + 1, n + 1)) /reduce(operator.mul, range(1, k +1))

        def fac(n):  
            return reduce(operator.mul, range(1,n+1))
            
        return c(2*n, n)/(n+1)
```