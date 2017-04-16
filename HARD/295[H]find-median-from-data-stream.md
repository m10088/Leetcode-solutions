[原题](https://leetcode.com/problems/find-median-from-data-stream)

题意

题解

```
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (even) { // 如果是偶数，那么先加入右边，然后从右边转移一个元素到左边，最后其实就是加入到了左边
            minHeap.push(num);
            
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
        } else { // 如果是奇数，那么应该先加入左边，然后转移一个元素到右边，其实最后就是加入到了右边
            maxHeap.push(num);
            int tmp = maxHeap.top();
            
            maxHeap.pop();
            minHeap.push(tmp);
        }
        even = 1-even;
    }
    
    
    
    double findMedian() {
        
        if (even==0) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
    
private:

    priority_queue<int,vector<int>,less<int>> maxHeap;      //最大值优先
    priority_queue<int,vector<int>,greater<int>> minHeap;   //最小值优先
    int even = 1;                                           // 当前是不是偶数
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```