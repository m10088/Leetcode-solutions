[原题](https://leetcode.com/problems/rotate-image/)

题意：

顺时针（逆时针）旋转一个2d的数组。


使用python的语言的库函数。

```
matrix[:] = zip( *matrix[::-1])
```

但是速度很慢。


可以原地每四个元素交换。

```Python
class Solution(object):
    def rotate(self, m):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        l = len(m)
        b = l-1
        for i in range((l+1)/2): 
            for j in range(i,b-i):
                #4-way swap
                m[i][j], m[j][b-i], m[b-i][b-j], m[b-j][i] = m[b-j][i],m[i][j], m[j][b-i], m[b-i][b-j]
            
```

实际上是吧数组分成了4个部分，但是，并不是每个元素都进行，交换，如果是这样，那么就相当于没有交换。

```Python
class Solution(object):
    def rotate(self, m):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        l = len(m)
        b = l-1
        for i in range((l+1)/2): 
            for j in range(i,b-i):
                #4-way swap
                m[i][j], m[j][b-i], m[b-i][b-j], m[b-j][i] = m[b-j][i],m[i][j], m[j][b-i], m[b-i][b-j]
            
```
