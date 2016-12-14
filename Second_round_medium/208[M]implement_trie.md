[原题](https://leetcode.com/problems/implement-trie-prefix-tree/)

题意：

实现trie树。


原理算是比较简单吧，但是以前总是使用递归的方式，边界处理的也不是很好。这次使用了迭代的方式进行、


```
class TrieNode:
        # Initialize your data structure here.
        def __init__(self):
            self.word=False
            self.children={}
    
    class Trie:
    
        def __init__(self):
            self.root = TrieNode()
    
        # @param {string} word
        # @return {void}
        # Inserts a word into the trie.
        def insert(self, word):
            node=self.root
            for i in word:
                if i not in node.children:
                    node.children[i]=TrieNode()
                node=node.children[i]
            node.word=True
    
        # @param {string} word
        # @return {boolean}
        # Returns if the word is in the trie.
        def search(self, word):
            node=self.root
            for i in word:
                if i not in node.children:
                    return False
                node=node.children[i]
            return node.word
    
        # @param {string} prefix
        # @return {boolean}
        # Returns if there is any word in the trie
        # that starts with the given prefix.
        def startsWith(self, prefix):
            node=self.root
            for i in prefix:
                if i not in node.children:
                    return False
                node=node.children[i]
            return True
```