[原题](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array)

题意:

求一个数组中两个数字的XOR的最大值。


题解:

暴力肯定是超时的，但是始终是没有思路，看来下tag，想到了一种思路，就是将一个数字的32位全部全部列出来，然后从高位到低位插入到一个二叉树中（trie树的变形），二叉树的两个分支分别对应0和1。这样，这个二叉树的层数是32层。

然后在一个数字插入之前，首先和已经存在的数字，进行异或，也就是沿着二叉树往下走，每次都尽量走和自己的那一位不同的一个分支，记录下走的分支，也就算出了，这个数字和以前的数字的最大的异或值。

那么以前的数字全部混在一起不会乱吗？

因为二叉树的良好特征，是不会混淆的，画个图，举个例子就可证明。

```
class Node(object):
    def __init__(self, one=None, zero=None):
        self.one = one
        self.zero = zero
        
def insert(node, val, cur): # 开始的时候是31，直到变为0
    if cur == -1: return
    tmp = val & (1<<cur)
    if tmp == 0:
        if not node.zero:
            node.zero = Node()
        insert(node.zero, val, cur-1)
    else:
        if not node.one:
            node.one = Node()
        insert(node.one, val, cur-1)
    
def get_max(root, val):# 这里使用迭代的方式处理
    p, res = root, 0
    for i in range(31, -1, -1):
        tmp = val & (1<<i)
        # 都尽量向相反的方向运动
        if tmp == 0: 
            if p.one: p, res = p.one, res * 2 + 1
            else: p, res = p.zero, res * 2
        else:
            if p.zero: p, res = p.zero, res * 2 + 1
            else: p, res = p.one, res * 2
    assert p.one == None and p.zero == None
    return res
    
class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        root, ret = Node(), 0
        insert(root, nums[0], 31)
        for i in range(1, len(nums)):
            tmp = get_max(root, nums[i])
            insert(root, nums[i], 31)
            ret = max(ret, tmp)
        return ret
```
