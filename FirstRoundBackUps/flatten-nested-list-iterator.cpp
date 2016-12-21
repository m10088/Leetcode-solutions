/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {

public:
    bool isempty(const NestedInteger& x){
        if(x.isInteger()==true)return false;
        auto v=x.getList();
        for(int i=v.size()-1;i>=0;i--){
            if(isempty(v[i])==false)return false;
        }
        return true;
    }
    vector<NestedInteger> stack;
    NestedIterator(vector<NestedInteger> &v) {
        //åç¬å¤çç¹æ®æåµ
        
        for(int i=v.size()-1;i>=0;i--){
            if(isempty(v[i]))continue;
            
            stack.push_back(v[i]);
        }
        
    }
    int next() {
        while(stack.back().isInteger()==false){
            auto back=stack.back().getList();
            stack.pop_back();
            for(int i=back.size()-1;i>=0;i--){
                if(isempty(back[i]))continue;
                stack.push_back(back[i]);
            }
        }
        int ret = stack.back().getInteger();
        stack.pop_back();
        return ret;
    }

    bool hasNext(){
       if(stack.empty())return false;
       else return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */