[原题](https://leetcode.com/problems/palindrome-linked-list/)

题意：

判断链表是不是回文的。

思路，快慢指针分割链表，然后，反转第二个链表，然后比较两个链表。
小心的处理，第一个链表比第二个链表长度大一的情况。

```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        pre = None
        p = head
        while p:
            tmp = p.next
            p.next = pre
            pre = p
            p = tmp
        return pre
        
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # split the list into two part and reverse tha last part then compare with each other
        
        if not head or not head.next: return True
        
        p = head
        q = head
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
            p = p.next
        p.next = self.reverseList(p.next)
        
        def compare(head1, head2):
            while head1.val == head2.val:
                head1 = head1.next
                head2 = head2.next
                if not head1 or not head2:
                    return True
            return False
        return compare(head, p.next)
        
        
        
```