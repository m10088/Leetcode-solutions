struct Node{
    Node* next[26];
    bool flag;
    Node(){
        memset(next,0,sizeof(next));
        flag=0;
    }
};
class WordDictionary {
public:
    Node root;
    void add_recur(Node&root,const string&s,int cur){
        if(cur==s.size()){
            root.flag=1;
            return;
        }
        if(root.next[s[cur]-'a']){//å¦æå·²ç»å­å¨äºè¿ä¸ªèç¹
            add_recur(*(root.next[s[cur]-'a']),s,cur+1);
        }else{
            root.next[s[cur]-'a']=new Node();
            add_recur(*(root.next[s[cur]-'a']),s,cur+1);
        }
    }

    bool search_recur(const Node&root,const string&s,int cur){
        if(cur==s.size()){
            return root.flag==1;
        }
    
        if(s[cur]=='.'){
            int flag=0;
            for(int i=0;i<26;i++){
                if(root.next[i]&&search_recur(*(root.next[i]),s,cur+1)){
                    flag=1;
                    break;
                }
            }
            if(flag)return true;
            else return false;
        }
    
        if(root.next[s[cur]-'a']){
            return search_recur(*(root.next[s[cur]-'a']),s,cur+1);
        }else{
            return false;
        }
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        add_recur(root,word,0);
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_recur(root,word,0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");