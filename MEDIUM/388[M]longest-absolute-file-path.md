[原题](https://leetcode.com/problems/longest-absolute-file-path)

题意:

```
The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
```


题解:

求绝对路径最长的文件（不是文件夹）名。



因此这道题目的最关键的是如何找到某个位置的parent目录，如果当前目录的的级别是3，那么前面最后一次出现2级别的位置，就是parent目录，因此只要不断的维护，x级别最后一次出现的位置就行。

```
class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        input = input.split('\n')
        print input
        
        def isFile(name):
            return name.find('.') != -1
        
        def getCntStr(string):
            p, cnt = 0, 0
            while string[p:p+1] == '\t':
                p, cnt = p + 1, cnt + 1
            return cnt, string[p:]
        
        dp = [None] * 100 # 记忆最近的第i层出现的index位置 
        fa = dict() # 父亲节点的index
        mmax = 0
        
        def getLen(idx):
            retLen, counter = 0, 0
            while fa[idx] != -1: retLen, idx, counter = retLen + len(input[idx]), fa[idx], counter + 1
            return retLen + len(input[idx]) + counter
            
                
        for i in range(0, len(input)):
            cnt, name = getCntStr(input[i])
            # 如果是根目录，如果不是根目录
            if cnt == 0: fa[i] = -1
            else: fa[i] = dp[cnt-1]
            
            dp[cnt], input[i] = i, name # 直接将input的内容更新
            
            if isFile(name): 
                print name, getLen(i)
                mmax = max(mmax, getLen(i))
        
        return mmax
```