class StockPrice {
private:
    map<int, int> cnt;
    map<int, int> m;
public:
    StockPrice(): cnt{}, m{} {}
    
    void update(int timestamp, int price) {
        if(m.find(timestamp)!=m.end()) {
            int prev=m[timestamp];
            --cnt[prev];
            if(!cnt[prev])
                cnt.erase(prev);
        }
        m[timestamp]=price;
        ++cnt[price];
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return cnt.rbegin()->first;
    }
    
    int minimum() {
        return cnt.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */