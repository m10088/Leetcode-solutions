#include<deque>
class Stack {
public:
    deque<int> d;
    // Push element x onto stack.
    void push(int x) {
        d.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        d.pop_back();
    }

    // Get the top element.
    int top() {
        return d.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return d.empty();
    }
};