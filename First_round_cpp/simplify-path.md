```c++
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        if path[-1] != '/':
            path += '/'
        l = path[1:][:-1].split('/')

        res = []
        for item in l:
            if item == '..':
                if len(res) > 0:
                    res.pop()
            elif item == '.' or item == '':
                pass
            else:
                res.append(item)
        ans = '/'
        for item in res:
            ans += str(item)
            ans += '/'
        if ans[:-1] == '':
            return '/'
        else:
            return ans[:-1
```
