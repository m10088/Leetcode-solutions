[原题](https://leetcode.com/problems/serialize-and-deserialize-bst)

题意:

实现字符串和二叉树结构之间的编码和解码，很简单。
在前序遍历的基础上，稍微修改即可。


题解:


```Python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        def dfs(root):
            if not root:
                res.append('#')
                return
            else:
                res.append(str(root.val))
                dfs(root.left)
                dfs(root.right)
        dfs(root)
        print res
        return ','.join(res)
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nodes = data.split(',')
        cur = [0] # 这里有一个Python的问题。
        def getTree():
            if nodes[cur[0]] == '#':
                cur[0] += 1
                return None
            root = TreeNode(int(nodes[cur[0]]))
            cur[0] += 1
            root.left = getTree()
            root.right = getTree()
            return root
        return getTree()
            
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```
