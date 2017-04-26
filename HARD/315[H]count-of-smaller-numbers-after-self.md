[原题](https://leetcode.com/problems/count-of-smaller-numbers-after-self)

题意

题解

```C++

/*这里的解决方案是将数据进行了离散化，之后使用书树狀数组解决的，*/
/*因为C++的STL没有提供相关的名次查询，所以，如果强行使用的话，那么可以使用https://www.zhihu.com/question/58776393这里的平板电视*/
/*当然也可以使用某些迭代器的操作思想但是复杂度会达到O(n)不是很好https://www.zhihu.com/question/50561064*/
/*总之，这个题目要想使用各种树解决，并且是O(nlgn)必须是平衡的树才行*/

/*假如你想使用各种树解决：参考这里https://discuss.leetcode.com/topic/33908/3-ways-segment-tree-binary-indexed-tree-binary-search-tree-clean-python-code*/

/*如果不想使用各种树解决，可是考虑MergeSort，还没有研究过。*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret, clone = nums;;
        int len = (int) nums.size();
        unordered_map<int, int> reflect;
        array.resize(len + 1);
        sort(clone.begin(), clone.end());
        for (int i = 0; i < len; ++ i)
            reflect[clone[i]] = i + 1;
        
        for (int i = len - 1; i >= 0; -- i) {
            clone[i] = query(reflect[nums[i]] - 1);
            add(reflect[nums[i]], 1);
        }
        return clone;
    }
    
private:
    vector<int> array;
    inline int lowbit(int pos) {
        return pos & -pos;
    }
    void add(int pos, int val) {
        long len = array.size();
        while (pos < len) {
            array[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += array[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};


```