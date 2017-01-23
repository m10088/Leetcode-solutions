[原题](https://leetcode.com/problems/reconstruct-original-digits-from-englishy)

题意:

Input: "owoztneoer"

Output: "012"

就是给定一些字母，已知这些字母是某些数字组合起来的，判断是那些数字。

题解:

首先应该想到的是矩阵的解法。

[26 * 10] * [10 * 1] = [26 * 1]的矩阵，26个方程10个未知数，很多的没有用的方程。最后大概是可以化简成10个未知数的线性非齐次方程。

但是这个比较难写代码。

TODO: 但是应该研究一下。

评论区给出了一种巧妙的解决方案。


```Python
class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        count = [0] * 10
        for c in s:
            if c == 'z': count[0]+=1
            if c == 'w': count[2]+=1
            if c == 'x': count[6]+=1
            if c == 'v': count[7]+=1 #7-5
            if c == 'g': count[8]+=1
            if c == 'u': count[4]+=1 
            if c == 'f': count[5]+=1 #5-4
            if c == 'h': count[3]+=1 #3-8
            if c == 'i': count[9]+=1 #9-8-5-6
            if c == 'o': count[1]+=1 #1-0-2-4
        # 注意拓扑排序的依赖关系
        count[5] -= count[4];
        count[7] -= count[5];
        count[3] -= count[8];
        count[9] = count[9] - count[8] - count[5] - count[6];
        count[1] = count[1] - count[0] - count[2] - count[4];
        res = ''
        for i in range(10):
            res += count[i] * str(i)
        return res
```

大致上的思路就是先找到那些含有独一无二的字符的数字。

```
if c == 'z': count[0]+=1
if c == 'w': count[2]+=1
if c == 'x': count[6]+=1
if c == 'g': count[8]+=1
if c == 'u': count[4]+=1 
```

也就是 0 2 4 6 8

然后举个例子，
```
if c == 'f': count[5]+=1 #5-4
```

就是最后5的结果要减去4的结果。

7的结果要减去5的结果。

再分析的话，就会发现，这里形成了一个拓扑关系，我们必须按照拓扑排序的关系求解。






