```c++
#include<deque>
class Stack {
public:
    deque<int> d;
    
    void push(int x) {
        d.push_back(x);
    }

    
    void pop() {
        d.pop_back();
    }

    
    int top() {
        return d.back();
    }

    
    bool empty() {
        return d.empty();
    }
}
```
