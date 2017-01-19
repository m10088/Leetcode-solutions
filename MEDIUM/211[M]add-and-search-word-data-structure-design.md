[原题](https://leetcode.com/problems/add-and-search-word-data-structure-design)

题意:

add & search word，并支持模糊查找，类似。

```
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```


题解:

就是一个trie树的数据结构，不过，因为支持模糊查询，如果遇到点的话，那么就应该遍历整个，节点的key。

```
class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.word = False
        self.children = {}

class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        node=self.root
        for i in word:
            if i not in node.children:
                node.children[i]=TrieNode()
            node=node.children[i]
        node.word=True
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        def aid(s, node):
            if not s: return True if node.word else False
            if s[0] == '.':
                for chidkey, childval in node.children.items():
                    if aid(s[1:], childval):
                        return True
                return False
            else:
                if s[0] not in node.children: return False
                return aid(s[1:], node.children[s[0]])
        return aid(word, self.root)
        
            
        

# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")
```
