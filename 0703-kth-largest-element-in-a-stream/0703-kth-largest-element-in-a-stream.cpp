class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;
public:
    KthLargest(int k, vector<int>& nums) : sz{k} {
        for(auto x:nums) {
            if(pq.size()>sz && x<=pq.top()) continue;
            pq.push(x);
            if(pq.size()>sz) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>sz) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */