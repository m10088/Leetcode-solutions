class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int> >left;//å¤§é¡¶å 
    priority_queue<int,vector<int>,greater<int> >right;//å°é¡¶å 
    int size=0;
public:
    void addNum(int num) {
        if(size==0){
            right.push(num);
            size++;
        }else if(size==1){
            if(num>right.top()){
                left.push(right.top());
                right.pop();
                right.push(num);
            }else{
                left.push(num);
            }
            size++;
        }else if(size%2==0){//ç°å¨æ¯æå¶æ°ä¸ªæ°
            if(num>left.top()){
                right.push(num);
            }else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            size++;
        }else{//ç°å¨æ¯å¥æ°ä¸ªæ°
            if(num<right.top()){
                left.push(num); 
            }else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            size++;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(size%2==0){
            return (left.top()+right.top())/2.0;
        }else{
            return right.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();