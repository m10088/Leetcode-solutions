[原题](https://leetcode.com/problems/add-two-numbers/)

题意：

两个数是用链表表示的，对他们进行加法将结果仍然放到链表当中。

模拟即可，注意特殊情况。

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        if not l1:return l2
        if not l2:return h1
        retDummy = ListNode(-1)
        cur = retDummy
        h1, h2 = l1, l2
        carry, s = 0, 0
        while True:
            if not h1 and h2:
                s = (h2.val + carry) % 10
                carry = (h2.val + carry) // 10
                h2 = h2.next
            elif not h2 and h1:
                s = (h1.val + carry) % 10
                carry = (h1.val + carry) // 10
                h1 = h1.next
            elif h1 and h2:
                s = (h1.val + h2.val + carry) % 10
                carry = (h1.val + h2.val + carry) // 10
                h2 = h2.next
                h1 = h1.next
            else:
                break
            # add the res to the retlinklist
            cur.next = ListNode(s)
            cur = cur.next
        # pay attention here!
        if carry:
            cur.next = ListNode(carry)
        return retDummy.next
            
        
```