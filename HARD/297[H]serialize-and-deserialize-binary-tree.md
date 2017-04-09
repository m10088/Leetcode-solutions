[原题](https://leetcode.com/problems/serialize-and-deserialize-binary-tree)

题意

题解

```
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
        ret = []
        def dfs(root):
            if root:
                ret.append(str(root.val))
                dfs(root.left)
                dfs(root.right)
            else:
                ret.append('#')
        dfs(root)
        print ret
        return ','.join(ret)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nodes = data.split(',')
        cur = [0]
        def build():
            
            if nodes[cur[0]] == '#':
                cur[0] += 1
                return None
            else:
                root = TreeNode(int(nodes[cur[0]]))
                cur[0] += 1
                root.left = build()
                root.right = build()
                return root
        return build()
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```