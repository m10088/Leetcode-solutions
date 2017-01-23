[原题](https://leetcode.com/problems/simplify-path/)

题意：

给定linux的路径，将其化简。

只要明白了```..```是返回上一个目录就可以了。

同时需要注意很多特殊情况，code tells everything。


```Python
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        tmp_objs, objs = path.split('/'), []
        #remove empty objs
        cur = []
        for item in tmp_objs:
            if item == '': continue
            if item == '.': continue
            elif item == '..':
                if len(cur)!=0: cur.pop()
            else:
                cur.append(item)
        if not cur: return '/'
        ret = ''
        for item in cur:
            ret += ('/' + str(item))
        return ret
```
