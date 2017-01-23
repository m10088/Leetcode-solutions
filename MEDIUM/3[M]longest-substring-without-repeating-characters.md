[原题](https://leetcode.com/problems/longest-substring-without-repeating-characters/)


题意：

求字符串中最长的没有重复元素的子串。


扫描每一个字符，如果没有出现过，加入hash，并更新结果的值。

如果出现过了，那么将当前窗口的已经出现位置的前面的所有元素全部弹出当前窗口，(hash delet)。

```Python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) <= 1: return len(s)
        mp = dict() 
        mp[s[0]] = 0 # record_position
        l = 0 # left_pointer
        ret = 0 # max_length_record
        for i in range(1, len(s)):
            if s[i] not in mp:
                mp[s[i]] = i
            else:
                origin_pos = mp[s[i]]
                # remove objs in the map
                while l <= origin_pos:
                    del mp[s[l]]
                    l += 1
                mp[s[i]] = i
            ret = max(ret, i-l+1)
        return ret
                    
```