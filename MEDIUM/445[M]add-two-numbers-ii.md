[原题](https://leetcode.com/problems/add-two-numbers-ii)

题意:

给定两个链表代表两个数字，求他们的和，的数组表示形式。

题解:

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def get_num(head):
            res, p = 0, head
            while p:
                res = res * 10 + p.val
                p = p.next
            return res
        s = get_num(l1) + get_num(l2)
        ls = [int(char) for char in str(s)]
        dummy = ListNode(-1)
        p = dummy
        for num in ls:
            p.next = ListNode(num)
            p = p.next
        return dummy.next
```

