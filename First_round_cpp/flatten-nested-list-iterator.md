```c++
/**
* 
* 
* class NestedInteger {
    * public:
    * 
    * bool isInteger() const;
    *
    * 
    * 
    * int getInteger() const;
    *
    * 
    * 
    * const vector<NestedInteger> &getList() const;
    * };
*/

class NestedIterator {

    public:
        bool isempty(const NestedInteger& x) {
            if (x.isInteger() == true)return false;
            auto v = x.getList();
            for (int i = v.size() - 1; i>=0;i--) {
                if (isempty(v[i]) == false)return false;
            }
            return true;
        }
        vector<NestedInteger> stack;
        NestedIterator(vector<NestedInteger> &v) {
            

            for (int i = v.size() - 1; i>=0;i--) {
                if (isempty(v[i]))continue;

                stack.push_back(v[i]);
            }

        }
        int next() {
            while (stack.back().isInteger() == false) {
                auto back = stack.back().getList();
                stack.pop_back();
                for (int i = back.size() - 1; i>=0;i--) {
                    if (isempty(back[i]))continue;
                    stack.push_back(back[i]);
                }
            }
            int ret = stack.back().getInteger();
```
