[原题](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

题意：

将一个排好序的linklist转化成bst，和数组的情况类似，最难的部分就是数组的划分。

考虑一些特殊的情况即可。

```

def split(head):
    dummy = ListNode(-1)
    dummy.next = head
    p, q, pre = head, head, dummy
    while q:
        if q.next:
            q = q.next
        else:
            break
        if q.next:
            q = q.next
        else:
            break
        # think why we do this here ?
        pre = p
        p = p.next
    pre.next = None
    return (dummy.next, p)

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head: return None
        left, mid = split(head)
    
        root = TreeNode(mid.val)
        root.left = self.sortedListToBST(left)
        root.right = self.sortedListToBST(mid.next)
        return root
```
