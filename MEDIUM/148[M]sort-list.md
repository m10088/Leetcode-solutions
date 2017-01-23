[原题](https://leetcode.com/problems/sort-list/)

题意：

链表的归并排序：

主要是将以前写过的两个function，合理的组合一下。

```Python
def mergeTwoLists(l1, l2):
        nummy = ListNode(-1)
        p = nummy
        while True:
                if not l1 and not l2:
                    break
                if l1 and l2 and l1.val <= l2.val or not l2:
                    
                    tmp = l1
                    l1 = l1.next
                    p.next = tmp
                    p = p.next
                    
                elif l1 and l2 and l1.val > l2.val or not l1:
                    
                    tmp = l2
                    l2 = l2.next
                    p.next = tmp
                    p = p.next
        return nummy.next

# call this function, when the number elment >= 2 
def paratation(head):
    # split the list into two part and reverse last part then compare with each other
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
    ret = p.next
    p.next = None
    return ret
    
def getlength(head):
    if not head: return 0
    p = head
    cnt = 0
    while p:
        cnt += 1
        p = p.next
    return cnt

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if getlength(head) < 2:
            return head
        mid = paratation(head)
        fir = self.sortList(head)
        sec = self.sortList(mid)
        return mergeTwoLists(fir, sec)
        
```

当然可以采用bottom_up的方法进行。

```C++
ListNode *sortList(ListNode *head) {
		if(!head || !(head->next)) return head;
		
		//get the linked list's length
		ListNode* cur = head;
		int length = 0;
		while(cur){
			length++;
			cur = cur->next;
		}
		
		ListNode dummy(0);
		dummy.next = head;
		ListNode *left, *right, *tail;
		for(int step = 1; step < length; step <<= 1){
			cur = dummy.next;
			tail = &dummy;
			while(cur){
				left = cur;
				right = split(left, step);
				cur = split(right,step);
				tail = merge(left, right, tail);
			}
		}
		return dummy.next;
	}
```


helper_function.

```C++

/**
	 * Divide the linked list into two lists,
     * while the first list contains first n ndoes
	 * return the second list's head
	 */
	ListNode* split(ListNode *head, int n){
		//if(!head) return NULL;
		for(int i = 1; head && i < n; i++) head = head->next;
		
		if(!head) return NULL;
		ListNode *second = head->next;
		head->next = NULL;
		return second;
	}
	/**
	  * merge the two sorted linked list l1 and l2,
	  * then append the merged sorted linked list to the node head
	  * return the tail of the merged sorted linked list
	 */
	ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
		ListNode *cur = head;
		while(l1 && l2){
			if(l1->val > l2->val){
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
			else{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
		}
		cur->next = (l1 ? l1 : l2);
		while(cur->next) cur = cur->next;
		return cur;
	}
```