```c++
class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int> >left;
    priority_queue<int,vector<int>,greater<int> >right;
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
        }else if(size%2==0){
            if(num>left.top()){
                right.push(num);
            }else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            size++;
        }else{
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

    
    double findMedian() {
        if(size%2==0){
            return (left.top()+right.top())/2.0;
        }else{
            return right.top();
        }
    }
};
```
