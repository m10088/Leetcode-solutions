[原题](https://leetcode.com/problems/word-ladde)

题意:

给定一个单词集合，和首位的两个单词，然后判断是不是可以组成一个单词的梯子，这个梯子上的两个单词之间字母的个数相同，但是只有一个位置上的字符是不同的。



题解:


首先想到的就是bfs啊，每个单词预处理出来，能够到达的单词，然后一遍bfs即可。

但是很不幸超时了。

于是看了一下discuss，其实也是bfs，不过在预处理的时候，不是遍历这个单词的集合，而是，手动改变单词的每个位置，并尝试26种修改方法，然后判断修改后的单词是不是在hash表中。

同时也不一定需要预处理，可以每走一步处理一下。

```
import string
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: Set[str]
        :rtype: int
        """
        def extend_q(word):
            for i in range(len(word)):
                for letter in string.ascii_lowercase:
                    new = word[:i] + str(letter) + word[i+1:]
                    if new != word and new in wordList:
                        q.append([new, step+1])
                        wordList.remove(new)
            
        q = [(beginWord, 1)]
       
        while len(q) > 0:
            froword, step = q.pop(0)
            # print froword, step
            if froword == endWord: return step
            extend_q(froword)
            
        return 0
                    
        
        
        
```