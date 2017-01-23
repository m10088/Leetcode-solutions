[原题](https://leetcode.com/problems/remove-k-digits)

题意:

这道题目，做了好久细节实在是太多，也可能我的代码写搓了。

对于一个数字num如果移除1个数字，很简单：

例如 1235432，第一次开始下降的位置是54，那么应该移除5。

10003，显然是移除1，那么前导0，也应当删除。

如果12345，那么找不到下降趋势的数字，那么应该从后面开始挨个删除。


如果真的是一个数字一个数字的删除，那么一定会超时。

仔细分析模拟之后，如果想一遍遍历，使用一个stack就可以了。

题解:


```Python
class Solution(object):
    def removeKdigits(self, nums, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        def removeleadingzeros(s):
            p = 0
            while p != len(s) and s[p] == '0': p += 1
            return s[p:]
        
        nums = [int(x) for x in nums]
        n, stack = len(nums), [(nums[0], 0)]
        if n == k: return '0'
        
        removed_index = set()
        for i in range(1, n):
            if nums[i] == 0:
                terminate = False              
                while len(stack) != 0:
                    removed_index.add(stack[-1][1])
                    stack.pop(-1)
                    k -= 1
                    if k == 0:
                        terminate = True
                        break
                if terminate: break
                else: removed_index.add(i)
            else:
                terminate = False
                while len(stack) != 0 and stack[-1][0] > nums[i]:
                    removed_index.add(stack[-1][1])
                    stack.pop(-1)
                    k -= 1
                    if k == 0:
                        terminate = True
                        break
                if terminate: break
                stack.append((nums[i], i))
                
        res = ''
        for i in range(n):
            if i not in removed_index: res += str(nums[i])
        
        res = removeleadingzeros(res)
        ret = res if k == 0 else res[:-k]
        return ret if ret != '' else '0'

```

其实这个前导0问题，这里处理的也不是很好，判断的特殊情况比较多，评论区[discuss](https://discuss.leetcode.com/category/527)有使用stack的更好的解决方案。