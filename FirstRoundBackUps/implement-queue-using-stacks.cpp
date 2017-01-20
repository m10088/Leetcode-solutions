#include<deque>
class Queue {
public:
    deque<int> d;
    
    void push(int x) {
        d.push_back(x);
    }

    
    void pop(void) {
        d.pop_front();
    }

    
    int peek(void) {
        return d.front();
    }

    
    bool empty(void) {
        return d.empty();
    }
};