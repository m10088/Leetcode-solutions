[原题](https://leetcode.com/problems/text-justification)

题意

题解

```
class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        if not words: return []
        def split(words, wid):
            """返回分割之后的list[list[str]]"""
            
            def ok(tmpList):
                ret = sum([len(word) for word in tmpList]) + len(tmpList) - 1
                return True if ret <= wid else False
            
            ret = []
            i, n = 0, len(words)
            while i < n:
                j = i
                while ok(words[i:j+1]) and j < n:
                    j += 1
                ret.append(words[i:j])
                i = j
            return ret
        
        ret, group = [], split(words, maxWidth)
        # 分割好了之后进行展示
        for i in range(len(group)-1):
            li = group[i]
            # 特殊情况，只有一个单词
            if len(li) == 1:
                ret.append(li[0] + ' ' * (maxWidth-len(li[0])))
                continue
            blanks = maxWidth - sum([len(word) for word in li])
            spliter = len(li) - 1
            each, left = blanks // spliter, blanks % spliter
            # 下面是错误的解法
            # string = li[0] + ' ' * (left)
            # for i in range(1, len(li)):
            #     string += (' ' * each + li[i])
            string = li[0]
            for i in range(1, len(li)):
                if i <= left:
                    string += (' ' * (each + 1) + li[i])
                else:
                    string += (' ' * (each) + li[i])
            ret.append(string)
            
        # 最后一行需要特殊处理
        li = group[-1]
        string = ' '.join(li)
        string += ' ' * (maxWidth - len(string))
        ret.append(string)
        
        return ret
        
        
                
```