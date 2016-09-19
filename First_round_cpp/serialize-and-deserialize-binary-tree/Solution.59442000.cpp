/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//stringè½¬åæint
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

//string è½¬åævector
template<typename T>
std::vector<T> StringToVec(const std::string &s){
    std::stringstream sout;
    sout << s;
    std::vector<T> res;
    T tmp;
    while(sout >> tmp){
        res.push_back(tmp);
    }
    return res;
}
template<typename T>
//intè½¬åæstring
std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
}


class Codec{
public:
    
    //ååºéå
    void Preorder(TreeNode*root,vector<string>&res){
        if(root){
            res.push_back(ToString<int>(root->val));
            Preorder(root->left,res);
            Preorder(root->right,res);
        }else{
            res.push_back("#");
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string>res;
        Preorder(root,res);
        string ans;
        for(auto &mem:res){
            ans+=mem;
            ans+=" ";
        }
        cout<<ans<<endl;
        return ans;
        
    }
    
    
    
    
    
    
    void build(TreeNode*&root,int& cur,const vector<string>&v){
        if(v[cur][0]=='#'){//è¡¨ç¤ºç»æäº
            root=NULL;
            cur++;
            return;
        }
        int value=StringTo<int>(v[cur++]);
        root=new TreeNode(value);
        build(root->left,cur,v);
        build(root->right,cur,v);
    }
    
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {//éç¨ååºéåçæ¹å¼
        vector<string> v=StringToVec<string>(data);
        int cur=0;
        TreeNode*root;
        build(root,cur,v);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));