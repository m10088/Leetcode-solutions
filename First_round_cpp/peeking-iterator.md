```c++


class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	
	int next();
	
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    this->next();
	}
    
	int peek() {
        return nextval;
	}

	
	
	int next() {
	    int res=nextval;
	    if(Iterator::hasNext()){
	        state=true;
	        nextval=Iterator::next();
	    }else{
	        state=false;
	    }
	    return res;
	}

	bool hasNext() const {
	    return state;
	}
	
private:
    bool state;
    int nextval;
}
```
