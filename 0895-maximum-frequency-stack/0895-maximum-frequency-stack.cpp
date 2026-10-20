class FreqStack {
private:
    unordered_map<int, vector<int>> m;
    unordered_map<int, int> freq;
    int maxx;
public:
    FreqStack(): freq{}, m{}, maxx{0} {}
    
    void push(int val) {
        if(freq.find(val)==freq.end())
            freq[val]=0;
        ++freq[val];
        m[freq[val]].push_back(val);
        maxx=max(maxx, freq[val]);
    }
    
    int pop() {
        int ans=m[maxx].back();
        m[maxx].pop_back();
        --freq[ans];
        if(m[maxx].empty()) --maxx;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */