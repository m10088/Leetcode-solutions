[原题](https://leetcode.com/problems/compare-version-numbers/)

题意：

比较两个版本号的大小。注意细节。

```
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        version01 = [int(s) for s in version1.split('.')]
        version02 = [int(s) for s in version2.split('.')]
        
        while len(version01) > 0 and version01[-1] == 0: version01.pop()
        while len(version02) > 0 and version02[-1] == 0: version02.pop()
        
        print version01
        print version02
        
        if len(version01) == 0: version01.append(0)
        if len(version02) == 0: version02.append(0)
        
        if version01 < version02:
            return -1
        elif version01 > version02:
            return 1
        else:
            return 0
```
