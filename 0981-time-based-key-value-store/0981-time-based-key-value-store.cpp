class TimeMap {
private:
    unordered_map<string, vector<int>> m;
    unordered_map<int, string> kv;
public:
    TimeMap(): m{} {}
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(timestamp);
        kv[timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()) return "";
        auto itr=upper_bound(m[key].begin(), m[key].end(), timestamp);
        if(itr==m[key].begin()) return "";
        --itr;
        return kv[*itr];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */