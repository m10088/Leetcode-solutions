[原题](https://leetcode.com/problems/minimum-window-substring)

题意

题解

```Python
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # 由于直接使用map这种方式需要涉及到map的比较问题，因此每次比较都要遍历map不符合O(n)的复杂度，合理的方法如下
        map = [0] * 128
        for char in t: map[ord(char)] += 1
        
        counter = len(t)
        l, r, n = 0, 0, len(s)
        curlen, rechead = float('inf'), 0
        while r < n:
            # print l, r
            if map[ord(s[r])] > 0: # 如果s[r]这个字符在t中，那么有关记录减去相应的值
                counter -= 1 # 只有那个目标字母资源还有的时候，才进行消耗
            map[ord(s[r])] -= 1
            r += 1
            
            while counter == 0: # 说明当前已经包含了t，那么尽可能地缩小s的大小
                # 更新
                if r - l < curlen:
                    rechead = l
                    curlen = r - l
                
                if map[ord(s[l])] == 0: # 如果最左边的字母在t中，那么增加相应值
                    counter += 1
                
                map[ord(s[l])] += 1
                l += 1
            
        if curlen == float('inf'): return ''
        else: return s[rechead: rechead+curlen]
            
            
        # 考虑另外一种情况，就是不需要统计次数，最小的子字符串，包含了所有的t中的字母即可。
                
        
                
```