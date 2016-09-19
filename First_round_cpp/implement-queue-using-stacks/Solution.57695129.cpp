#include<deque>
class Queue {
public:
    deque<int> d;
    // Push element x to the back of queue.
    void push(int x) {
        d.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        d.pop_front();
    }

    // Get the front element.
    int peek(void) {
        return d.front();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return d.empty();
    }
};