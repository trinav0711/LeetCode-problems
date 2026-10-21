class Solution {
private:
    int bt(int cur, unordered_map<int,int>&m) const {
        if(m.find(cur)!=m.end())
            return m[cur];
        if(cur%2==0)
            m[cur]=bt(cur/2,m);
        else
            m[cur]=bt(3*cur+1, m);
        ++m[cur];
        return m[cur];
    }
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int>m;
        m[1]=0;
        for(int i=lo;i<=hi;++i)
            bt(i, m);
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;++i) {
            v.push_back({m[i], i});
        }
        sort(v.begin(), v.end());
        return v[k-1].second;
    }
};