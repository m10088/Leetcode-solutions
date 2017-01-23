[原题](https://leetcode.com/problems/surrounded-regions)

题意：

找出二维数组中被X包围的O。


首先应该想到的思路就是，先将边界的地区，全部进行BFS或者DFS，找到相连的方块，进行标记，标记可以作为S吧，然后，将那些没有翻转到的O，全部翻转，然后将S复原。


```Python
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not any(board): return
    
        m, n = len(board), len(board[0])
        save = [ij for k in range(m+n) for ij in ((0, k), (m-1, k), (k, 0), (k, n-1))]
        while save:
            i, j = save.pop()
            if 0 <= i < m and 0 <= j < n and board[i][j] == 'O':
                board[i][j] = 'S'
                save += (i, j-1), (i, j+1), (i-1, j), (i+1, j)
    
        board[:] = [['XO'[c == 'S'] for c in row] for row in board]
```

这里面有两个有意思的函数。

any和all。

这里是python的官方说明。

```
 any(iterable) -> bool
    
    Return True if bool(x) is True for any x in the iterable.
    If the iterable is empty, return False.

```

```
 all(iterable) -> bool
    
    Return True if bool(x) is True for all values x in the iterable.
    If the iterable is empty, return True.

```

也就是any如果有一个对象是true就返回true，否则返回false。

all，如果所有的对象都是true才返回true，否则返回false。

空的情况，可以参考上面。



评论区，有人使用了并查集。

基本思想，就是建立一个dummy的节点，扫描所有的O，如果是边界上的话，就将他连接到dummy的节点，如果不是那么就和上下左右中的的那些O点进行相连。

最后看一下，有多少个O是不和dummy，相连的。

```C++
class UF
{
private:
    int* id;     // id[i] = parent of i
    int* rank;  // rank[i] = rank of subtree rooted at i (cannot be more than 31)
    int count;    // number of components
public:
    UF(int N) {
        count = N;
        id = new int[N];
        rank = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            rank[i] = 0;
        }
    }
    ~UF() {
        delete [] id;
        delete [] rank;
    }
    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];    // path compression by halving
            p = id[p];
        }
        return p;
    }
    int getCount() { return count; }
    bool connected(int p, int q) { return find(p) == find(q); }
    void connect(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (rank[i] < rank[j]) id[i] = j;
        else if (rank[i] > rank[j]) id[j] = i;
        else {
            id[j] = i;
            rank[i]++;
        }
        count--;
    }
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if(n==0)    return;
        int m = board[0].size();
        UF uf = UF(n*m+1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1)&&board[i][j]=='O') // if a 'O' node is on the boundry, connect it to the dummy node
                    uf.connect(i*m+j,n*m);
                else if(board[i][j]=='O') {// connect a 'O' node to its neighbour 'O' nodes
                    if(board[i-1][j]=='O') uf.connect(i*m+j,(i-1)*m+j);
                    if(board[i+1][j]=='O') uf.connect(i*m+j,(i+1)*m+j);
                    if(board[i][j-1]=='O') uf.connect(i*m+j,i*m+j-1);
                    if(board[i][j+1]=='O') uf.connect(i*m+j,i*m+j+1);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!uf.connected(i*m+j,n*m)){ // if a 'O' node is not connected to the dummy node, it is captured
                    board[i][j]='X';
                }
            }
        }
    }
};
```