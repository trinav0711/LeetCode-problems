class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);
        if(!right.empty() && left.top()>right.top()) {
            right.push(left.top());
            left.pop();
            left.push(right.top());
            right.pop();
        }
        if(left.size()>right.size()+1) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()) return static_cast<double>(left.top());
        return static_cast<double>(((double)(left.top())+(double)(right.top()))/2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */