class RLEIterator {
private:
    vector<int> v;
    int cur;
public:
    RLEIterator(vector<int>& encoding): v{encoding}, cur{0} {}
    
    int next(int n) {
        if(cur>=v.size())
            return -1;
        for(cur;cur<v.size()-1 && n;cur+=2) {
            if(v[cur]>n) {
                v[cur]-=n;
                return v[cur+1];
            }
            n-=v[cur];
            v[cur]=0;
        }
        if(n)
            return -1;
        return v[cur-1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */