// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();//è¿éåä¸ä¸è¦ç»è¿å»ï¼å®éä¸å·²ç»ä¸ºä½ å®ç°å¥½äº
	// Returns true if the iteration has more elements.
	bool hasNext() const;//åçï¼ä¹æ¯ä¸ºä½ å®ç°å¥½äº
};

//ç®çå°±æ¯peekå½æ°
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    this->next();//ä¸ç¨thisï¼æ¾ä¸å°æ¬å°çï¼å°±ä¼å»æ¾ç¥åç
	}
    
	int peek() {
        return nextval;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
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
};