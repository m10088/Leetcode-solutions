```c++
class NumArray {
    public:
        int *bits;
        int N;
        void update(int x, int val) {
            for (; x < N; x += x&-x)
                bits[x] += val;
        }

        int query(int x) {
            int res = 0;
            for (; x; x -= x&-x)
                res += bits[x];
            return res;
        }

        NumArray(vector<int> &nums) {

            N = nums.size() + 7;
            bits = new int[N];
            for (int i = 0; i < N; i++){bits[i] = 0; }
            for (int i = 0; i < nums.size(); i++) {
                update(i + 1, nums[i]);
            }

        }

        int sumRange(int i, int j) {
            i++,j++;
            return query(j) - query(i - 1);
        }
};






```
