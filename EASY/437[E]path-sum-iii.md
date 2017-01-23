[原题](https://leetcode.com/problems/path-sum-iii/)

题意：

只能走竖直的路径，一共有几条路径之和能够得到target。

类似112， 113。

其实我们可以从上往下的遍历这棵树。对每一个节点，从上到下遍历一次，但是效率不高。

看了讨论区的一种思路非常不错，递归的某个节点的时候，传递给这个过程的是，还需要凑够的数目组成的数组。

因此，每次到达一个节点，更新这个数组。(数组每个节点都减去这个节点的val变量。)，因为不仅仅是从根节点起，需要在每个递归节点，将origin_tar加上。

```Python
class Solution(object):
    def pathSum(self, root, s):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        return self.helper(root, s, [s])

    def helper(self, node, ori, tgts):
        if not node: return 0
        hit = 0
        for t in tgts:
            if not t-node.val: hit += 1
        tgts = [t-node.val for t in tgts]+[ori]         # update the targets
        return hit+self.helper(node.left, ori, tgts)+self.helper(node.right, ori, tgts)
```

