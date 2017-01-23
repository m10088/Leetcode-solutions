[原题](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)


题意：


除去链表中，重复的元素。

1,2,3,3,4,5 -> 1,2,4,5

使用dict即可。

```C++
d = {}
node = head
while node:
    d[node.val] = d.get(node.val, 0) + 1
    node = node.next
duplicates = {k for k, v in d.items() if v > 1}
```


```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        d = {}
        node = head
        while node:
            d[node.val] = d.get(node.val, 0) + 1
            node = node.next
        
        duplicates = {k for k, v in d.items() if v > 1}
        
        dummy = ListNode(None)
        dummy.next = head
        
        node = dummy
        while node:
            if node.next and node.next.val in duplicates:
                node.next = node.next.next
            else:
                node = node.next
        
        return dummy.next
```