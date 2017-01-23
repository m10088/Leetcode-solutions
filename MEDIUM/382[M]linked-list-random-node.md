[原题](https://leetcode.com/problems/linked-list-random-node/)

题意：

从链表中随机的找出一个数字。



在不知道数组的个数的情况下，从n(未知)个数中随机找出k个数字。

蓄水池算法，k个数字作为开始的状态，第k+i个数字，以k+i的概率，随机的替换蓄水池中的一个数字。

证明可以采用数学归纳法。

[详细过程看这里](https://discuss.leetcode.com/topic/53753/brief-explanation-for-reservoir-sampling/2)


```Python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    
    # take a reference here: https://discuss.leetcode.com/topic/53753/brief-explanation-for-reservoir-sampling/2
    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.li = head

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        ret = self.li.val
        cur = 1
        p = self.li.next
        while p:
            # replace the single number(this case k == 1) in the cache
            if random.randint(0, cur) is 0:
                ret = p.val
            cur += 1
            p = p.next
        return ret

# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
```